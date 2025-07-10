cmake_minimum_required(VERSION 3.4.1)
project(gs_napi_demo)

include_directories(${GS_ROOT}/include)

add_library(gs_core SHARED IMPORTED)
set_target_properties(gs_core PROPERTIES
  IMPORTED_LOCATION ${GS_ROOT}/lib/libgs.so
)

add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi gs_core log)

set_target_properties(gs_napi PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/${ANDROID_ABI}
)
