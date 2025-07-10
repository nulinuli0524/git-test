cmake_minimum_required(VERSION 3.10)
project(gs_napi_demo)

# find system Ghostscript
find_library(GS_LIB gs REQUIRED)
find_path(GS_INC iapi.h PATHS /usr/include/ghostscript)

include_directories(${GS_INC})

add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi PRIVATE ${GS_LIB})

# ensure output name is libgs_napi.so
set_target_properties(gs_napi PROPERTIES
  OUTPUT_NAME "gs_napi"
)
