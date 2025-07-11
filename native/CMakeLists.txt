cmake_minimum_required(VERSION 3.10)
project(gs_napi_demo)

find_library(GS_LIB gs REQUIRED)
find_path(GS_INC
  NAMES iapi.h
  PATHS /usr/include/ghostscript /usr/local/include/ghostscript
  REQUIRED
)
find_path(NODE_API_INC
  NAMES node_api.h
  PATHS /usr/include /usr/include/node /usr/local/include
  REQUIRED
)

include_directories(${GS_INC} ${NODE_API_INC})

add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi PRIVATE ${GS_LIB})
set_target_properties(gs_napi PROPERTIES OUTPUT_NAME "gs_napi")
