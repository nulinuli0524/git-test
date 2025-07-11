#include "iapi.h"
#include <node_api.h>
#include <cstdio>

extern "C" int convert(const char* pdf_path, const char* pclm_path) { 
    void* gs = nullptr;
    if (gsapi_new_instance(&gs, nullptr) < 0) return -1; char out_arg[512]; std::snprintf(out_arg, sizeof(out_arg), "-sOutputFile=%s", pclm_path);
    const char* gs_args[] = { "gs", "-dNOPAUSE", "-dBATCH", "-sDEVICE=pclm", out_arg, pdf_path };
    int code = gsapi_init_with_args(gs, 6, const_cast<char**>(gs_args));
    gsapi_exit(gs); gsapi_delete_instance(gs); return code; 
}
// 原始转换函数
static napi_value ConvertPdfToPcl(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    char input[512], output[512];
    size_t len;

    napi_get_value_string_utf8(env, argv[0], input, sizeof(input), &len);
    napi_get_value_string_utf8(env, argv[1], output, sizeof(output), &len);

    void* gs = nullptr;
    gsapi_new_instance(&gs, nullptr);

    char out_arg[512];
    std::snprintf(out_arg, sizeof(out_arg), "-sOutputFile=%s", output);

    const char* gs_args[] = {
        "gs", "-dNOPAUSE", "-dBATCH",
        "-sDEVICE=pclm",
        out_arg,
        input
    };

    int code = gsapi_init_with_args(gs, 6, const_cast<char**>(gs_args));
    gsapi_exit(gs);
    gsapi_delete_instance(gs);

    napi_value result;
    napi_create_int32(env, code, &result);
    return result;
}

// N-API 注册模块
static napi_module gsModule = {
    .nm_version = 1,
    .nm_register_func = [](napi_env env, napi_value exports) -> napi_value {
        napi_property_descriptor desc = {
            "convert", nullptr, ConvertPdfToPcl,
            nullptr, nullptr, nullptr, napi_default, nullptr
        };
        napi_define_properties(env, exports, 1, &desc);
        return exports;
    },
    .nm_modname = "libgs_napi.so", // 或者 "gs_napi"，与你的 import 保持一致
    .reserved = {0}
};

// 构造时注册
__attribute__((constructor))
static void RegisterModule() {
    napi_module_register(&gsModule);
}
