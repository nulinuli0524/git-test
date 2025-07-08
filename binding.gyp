{
  "targets": [
    {
      "target_name": "pdf2pclm",
      "sources": [ "src/convert.cc" ],

      // ========= 包含 N-API 头文件和 Ghostscript 头文件 =========
      "include_dirs": [
        // 通过 node-addon-api 动态获取 include 路径
        "<!(node -p \"require('node-addon-api').include\")",
        // 兜底方案：直接指定到本地 node_modules
        "node_modules/node-addon-api",
        // Ghostscript headers
        "gs-headers"
      ],
      "dependencies": [
        // 确保 gyp 也拉取 node-addon-api 中的 gyp 配置
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],

      // ========= 链接 Ghostscript 静态库 及 其依赖 =========
      "libraries": [
        "libgs.a",
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
