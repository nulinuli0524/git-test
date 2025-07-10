cmake_minimum_required(VERSION 3.5)
project(pdf2pclm)

set(GS_LIB_PATH "${GS_LIB_PATH}" CACHE FILEPATH "Path to libgs.so")

add_library(pdf2pclm SHARED pdf2pclm.cpp)
target_link_libraries(pdf2pclm PRIVATE ${GS_LIB_PATH})
