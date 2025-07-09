cmake_minimum_required(VERSION 3.5)
project(pdf2pclm)

# GS_LIB_PATH is passed from CI
set(GS_LIB_PATH "${GS_LIB_PATH}" CACHE FILEPATH "Path to libgs.so")

add_library(pdf2pclm SHARED pdf2pclm.cpp)
# link against Ghostscript shared lib
target_link_libraries(pdf2pclm PRIVATE ${GS_LIB_PATH})
set_target_properties(pdf2pclm PROPERTIES OUTPUT_NAME "pdf2pclm")
