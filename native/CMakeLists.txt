cmake_minimum_required(VERSION 3.4)
project(gs_napi_demo)

# 找到系统安装的 Ghostscript 库和头文件
find_library(GS_LIB gs REQUIRED)
find_path(GS_INC NAMES iapi.h PATHS /usr/include/ghostscript)

include_directories(${GS_INC})

add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi PRIVATE ${GS_LIB})

set_target_properties(gs_napi PROPERTIES
  OUTPUT_NAME "libgs_napi"
)
