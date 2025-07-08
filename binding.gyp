{
  "targets": [
    {
      "target_name": "pdf2pclm",
      "sources": [ "src/convert.cc" ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include\")",
        "node_modules/node-addon-api",
        "gs-headers"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "libraries": [
        // 用 pwd 解析出工作区根目录下的 libgs.a 绝对路径
        "<!(pwd)/libgs.a",
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
