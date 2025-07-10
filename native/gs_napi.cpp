#include "iapi.h"
#include <cstdio>
#include <cstdlib>

extern "C" int convert(const char* pdf_path, const char* pclm_path) {
    void* gs = nullptr;
    if (gsapi_new_instance(&gs, nullptr) < 0) {
        return -1;
    }

    char out_arg[512];
    std::snprintf(out_arg, sizeof(out_arg), "-sOutputFile=%s", pclm_path);

    const char* gs_args[] = {
        "gs",
        "-dNOPAUSE",
        "-dBATCH",
        "-sDEVICE=pclm",
        out_arg,
        pdf_path
    };

    int code = gsapi_init_with_args(gs, 6, const_cast<char**>(gs_args));
    gsapi_exit(gs);
    gsapi_delete_instance(gs);
    return code;
}
