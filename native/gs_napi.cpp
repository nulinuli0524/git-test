#include <napi/native_api.h>
#include "iapi.h"

static napi_value ConvertPdfToPcl(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value argv[2];
  napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

  // 提取字符串参数
  char inputPath[512], outputPath[512];
  size_t len;
  napi_get_value_string_utf8(env, argv[0], inputPath, sizeof(inputPath), &len);
  napi_get_value_string_utf8(env, argv[1], outputPath, sizeof(outputPath), &len);

  // 初始化 Ghostscript 实例
  void* gsInst = nullptr;
  gsapi_new_instance(&gsInst, nullptr);

  // 构建参数
  const char* gsArgs[] = {
    "gs", "-dNOPAUSE", "-dBATCH",
    "-sDEVICE=pxlcolor",
    "-sOutputFile", outputPath,
    inputPath
  };

  int exitCode = gsapi_init_with_args(gsInst, 7, const_cast<char**>(gsArgs));
  gsapi_exit(gsInst);
  gsapi_delete_instance(gsInst);

  napi_value result;
  napi_create_int32(env, exitCode, &result);
  return result;
}

static napi_module gsModule = {
  .nm_version       = 1,
  .nm_register_func = [](napi_env env, napi_value exports) {
    napi_property_descriptor desc = {
      "convert", nullptr, ConvertPdfToPcl, nullptr, nullptr, nullptr, napi_default, nullptr
    };
    napi_define_properties(env, exports, 1, &desc);
    return exports;
  },
  .nm_modname       = "gs_napi",
  .reserved         = {0}
};

__attribute__((constructor))
static void RegisterModule() {
  napi_module_register(&gsModule);
}
