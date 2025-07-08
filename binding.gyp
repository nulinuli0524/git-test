{
  "targets": [
    {
      "target_name": "pdf2pclm",
      "sources": [ "src/convert.cc" ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include\")",
        "gs-headers"  // Ghostscript 头文件复制路径（build 脚本会生成）
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "libraries": [
        "libgs.a",           // 静态链接 Ghostscript 主库
        "-lpthread",
        "-lm",
        "-lz",
        "-ljpeg",
        "-lfreetype"
      ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
    }
  ]
}
