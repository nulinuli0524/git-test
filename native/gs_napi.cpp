#include <napi/native_api.h>
#include "iapi.h"

static napi_value Convert(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value argv[2];
  napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

  char input[256], output[256];
  size_t len;
  napi_get_value_string_utf8(env, argv[0], input, sizeof(input), &len);
  napi_get_value_string_utf8(env, argv[1], output, sizeof(output), &len);

  void* gs = nullptr;
  gsapi_new_instance(&gs, nullptr);

  const char* args[] = {
    "gs", "-dNOPAUSE", "-dBATCH",
    "-sDEVICE=pclm",
    "-sOutputFile", output,
    input
  };

  int code = gsapi_init_with_args(gs, 7, const_cast<char**>(args));
  gsapi_exit(gs);
  gsapi_delete_instance(gs);

  napi_value result;
  napi_create_int32(env, code, &result);
  return result;
}

static napi_module gsModule = {
  .nm_version = 1,
  .nm_register_func = [](napi_env env, napi_value exports) {
    napi_property_descriptor desc = {
      "convert", nullptr, Convert, nullptr, nullptr, nullptr, napi_default, nullptr
    };
    napi_define_properties(env, exports, 1, &desc);
    return exports;
  },
  .nm_modname = "gs_napi",
  .reserved = {0}
};

__attribute__((constructor))
static void Register() {
  napi_module_register(&gsModule);
}
