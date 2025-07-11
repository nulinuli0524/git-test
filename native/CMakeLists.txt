cmake_minimum_required(VERSION 3.10) project(gs_napi_demo)

if(NOT DEFINED GS_ROOT) message(FATAL_ERROR "GS_ROOT is not defined. Pass -DGS_ROOT=/path/to/ghostpdl/install") endif()

find_path(GHOSTSCRIPT_INCLUDE NAMES iapi.h PATHS ${GS_ROOT}/include/ghostscript /usr/include/ghostscript REQUIRED )

find_library(GHOSTSCRIPT_LIBRARY NAMES gs PATHS ${GS_ROOT}/lib /usr/lib /usr/lib/x86_64-linux-gnu REQUIRED )

find_path(NODE_API_INCLUDE NAMES node_api.h PATHS /usr/include /usr/include/node /usr/local/include REQUIRED )

include_directories( ${GHOSTSCRIPT_INCLUDE} ${NODE_API_INCLUDE} )

add_library(gs_napi SHARED gs_napi.cpp) target_link_libraries(gs_napi PRIVATE ${GHOSTSCRIPT_LIBRARY})

set_target_properties(gs_napi PROPERTIES OUTPUT_NAME "gs_napi" )
