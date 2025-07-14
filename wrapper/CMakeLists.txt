cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

# 要求从外部传入 Ghostscript 安装根路径
if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR
    "GS_ROOT 未定义。请通过 -DGS_ROOT=<ghostscript 安装路径> 传入")
endif()

# 包含头文件目录
include_directories(${GS_ROOT}/include)

# 生成共享库
add_library(pdf2pclm SHARED pdf2pclm.c)

# 链接 libgs.so
target_link_directories(pdf2pclm PRIVATE ${GS_ROOT}/lib)
target_link_libraries(pdf2pclm PRIVATE gs)

# 去掉前缀 “lib”，输出 pdf2pclm.so
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
