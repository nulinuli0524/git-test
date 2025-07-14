cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

# 只负责定义接口，把编译器/编译选项都交给外部传入
include_directories(
  ${CMAKE_SOURCE_DIR}/../ghostpdl/build_output/usr/local/ghostscript/include
)

find_library(GS_LIB gs
  PATHS ${CMAKE_SOURCE_DIR}/../ghostpdl/build_output/usr/local/ghostscript/lib
)

add_library(pdf2pclm SHARED pdf2pclm.c)
target_link_libraries(pdf2pclm PRIVATE ${GS_LIB})

# 去掉前缀 “lib”，生成文件名 pdf2pclm.so
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
