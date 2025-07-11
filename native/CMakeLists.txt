cmake_minimum_required(VERSION 3.10)
project(gs_napi_demo)

# 找 Ghostscript 库和头
find_library(GS_LIB gs REQUIRED)
find_path(GS_INC iapi.h PATHS /usr/include/ghostscript)

# 找 N-API 头
find_path(NODE_API_DIR node_api.h
  PATHS
    /usr/include
    /usr/include/node
)

# 把头都加进来
include_directories(
  ${GS_INC}
  ${NODE_API_DIR}
)

add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi PRIVATE ${GS_LIB})

# 确保输出名是 libgs_napi.so
set_target_properties(gs_napi PROPERTIES OUTPUT_NAME "gs_napi")
