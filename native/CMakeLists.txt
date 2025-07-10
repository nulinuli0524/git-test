cmake_minimum_required(VERSION 3.4.1)
project(gs_napi_wrapper)

# 1. 指定 Ghostscript 头文件位置
include_directories(${GS_ROOT}/include)

# 2. 声明预编译核心库 libgs.so
add_library(gs_core SHARED IMPORTED)
set_target_properties(gs_core PROPERTIES
  IMPORTED_LOCATION ${GS_ROOT}/lib/libgs.so
)

# 3. 编译 N-API 封装库 libgs_napi.so
add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi
  PUBLIC
    gs_core
    log
)

# 4. 输出目录（与 GitHub Action 上传路径一致）
set_target_properties(gs_napi PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/${ANDROID_ABI}
)
