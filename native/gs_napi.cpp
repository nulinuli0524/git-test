#include "iapi.h"
#include <node_api.h>
#include <cstdio>

static napi_value JsConvert(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    char pdfPath[512], pclmPath[512];
    size_t len;
    napi_get_value_string_utf8(env, argv[0], pdfPath, sizeof(pdfPath), &len);
    napi_get_value_string_utf8(env, argv[1], pclmPath, sizeof(pclmPath), &len);

    void* gs = nullptr;
    if (gsapi_new_instance(&gs, nullptr) < 0) {
        napi_value err; napi_create_int32(env, -1, &err);
        return err;
    }

    char outArg[512];
    std::snprintf(outArg, sizeof(outArg), "-sOutputFile=%s", pclmPath);
    const char* gs_args[] = {
        "gs", "-dNOPAUSE", "-dBATCH", "-sDEVICE=pclm", outArg, pdfPath
    };
    int code = gsapi_init_with_args(gs, 6, const_cast<char**>(gs_args));
    gsapi_exit(gs);
    gsapi_delete_instance(gs);

    napi_value result;
    napi_create_int32(env, code, &result);
    return result;
}

static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc = {
        "convert", nullptr, JsConvert,
        nullptr, nullptr, nullptr,
        napi_default, nullptr
    };
    napi_define_properties(env, exports, 1, &desc);
    return exports;
}

static napi_module moduleDef = {
    .nm_version       = 1,
    .nm_register_func = Init,
    .nm_modname       = "gs_napi",
    .reserved         = {0}
};

__attribute__((constructor))
static void RegisterModule() {
    napi_module_register(&moduleDef);
}
