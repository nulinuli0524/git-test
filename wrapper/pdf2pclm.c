#include "iapi.h"
#include "imemory.h"
#include <stdio.h>

int pdf_to_pclm(const char *in_pdf, const char *out_pclm) {
    void *gs_instance = NULL;
    const char *argv[] = {
        "pdf2pclm",
        "-dNOPAUSE",
        "-dBATCH",
        "-dSAFER",
        "-sDEVICE=pclm",
        NULL,  // 占位：输出参数
        NULL   // 占位：输入文件
    };
    int argc = 7;
    char output_arg[256];
    snprintf(output_arg, sizeof(output_arg), "-sOutputFile=%s", out_pclm);
    ((char **)argv)[5] = output_arg;
    ((char **)argv)[6] = (char *)in_pdf;

    if (gsapi_new_instance(&gs_instance, NULL) < 0) return -1;
    if (gsapi_init_with_args(gs_instance, argc, (char **)argv) < 0) {
        gsapi_exit(gs_instance);
        return -2;
    }
    gsapi_exit(gs_instance);
    return 0;
}
