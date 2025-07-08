{
  "targets": [
    {
      "target_name": "pdf2pclm",
      "sources": [
        "src/convert.cc"
      ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include\")",
        "node_modules/node-addon-api",
        "gs-headers"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "libraries": [
        "<!(pwd)/libgs.a",
        "-lpthread",
        "-lm",
        "-lz",
        "-ljpeg",
        "-lfreetype"
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ]
    }
  ]
}
