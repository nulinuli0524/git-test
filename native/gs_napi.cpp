#include "iapi.h"
#include <napi/native_api.h>
#include <cstdio>

// 从 JS
#include "iapi.h"
#include <napi/native_api.h>
#include <cstdio>

// 从 JS 层接收两个路径，返回转换结果
static napi_value JsConvert(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value 层接收两个路径，返回转换结果
static napi_value JsConvert(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    char in[512],);

    char in[512], out[512];
    size_t len;
    napi_get_value_string_utf8(env, argv[0], in, sizeof(in), &len);
    napi_get_value_string_utf8(env, argv[1], out[512];
    size_t len;
    napi_get_value_string_utf8(env, argv[0], in, sizeof(in), &len);
    napi_get_value_string_utf8(env, argv[1], out, sizeof(out), &len);

    void out, sizeof(out), &len);

    void* gs = nullptr;
    gsapi_new_instance(&gs, nullptr);

    char argOut[512];
* gs = nullptr;
    gsapi_new_instance(&gs, nullptr);

    char argOut[512];
    std::snprintf    std::snprintf(argOut, sizeof(argOut), "-sOutputFile=%s", out);

    const char* gs_args[] = {
        "(argOut, sizeof(argOut), "-sOutputFile=%s", out);

    const char* gs_args[] = {
        "gs", "-dNOPAUSE", "-dBATCH",
        "-sDEVICE=pclm",
        argOut,
gs", "-dNOPAUSE", "-dBATCH",
        "-sDEVICE=pclm",
        argOut,
        in
    };
    int code = gsapi_init_with_args(gs, 6, const_cast<char**>(gs_args));
    gsapi_exit(gs);
    gsapi_delete_instance(gs);

    napi_value result        in
    };
    int code = gsapi_init_with_args(gs, 6, const_cast<char**>(gs_args));
    gsapi_exit(gs);
    gsapi_delete_instance(gs);

    napi_value result;
    napi_create;
    napi_create_int32(env, code, &result);
    return result;
}

static napi_value Init(napi_env env, napi_int32(env, code, &result);
    return result;
}

static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc = {
        "convert", nullptr, JsConvert_value exports) {
    napi_property_descriptor desc = {
        "convert", nullptr, JsConvert, nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr
    };
    napi_define_properties(env, exports, 1, nullptr, napi_default, nullptr
    };
    napi_define_properties(env, exports, 1, &desc);
    return, &desc);
    return exports;
}

static napi_module moduleDef = {
    .nm_version       = 1,
    .nm_register_func = Init,
    .nm exports;
}

static napi_module moduleDef = {
    .nm_version       = 1,
    .nm_register_func = Init,
    .nm_modname       =_modname       = "libgs_napi.so",
    .reserved         = {0}
};

__attribute__((constructor))
static void Register "libgs_napi.so",
    .reserved         = {0}
};

__attribute__((constructor))
static void RegisterModule() {
    napi_module_register(&moduleDef);
}
Module() {
    napi_module_register(&moduleDef);
}
