#include <napi.h>
#include <cstdlib>
#include <string>

Napi::Value Convert(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2 || !info[0].IsString() || !info[1].IsString()) {
    Napi::TypeError::New(env, "Expected input and output file paths").ThrowAsJavaScriptException();
    return env.Null();
  }

  std::string inputPath = info[0].As<Napi::String>().Utf8Value();
  std::string outputPath = info[1].As<Napi::String>().Utf8Value();

  std::string cmd = "gs -dBATCH -dNOPAUSE -sDEVICE=pclm -sOutputFile=" + outputPath + " " + inputPath;
  int status = std::system(cmd.c_str());

  return Napi::Number::New(env, status);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("convert", Napi::Function::New(env, Convert));
  return exports;
}

NODE_API_MODULE(pdf2pclm, Init)
