cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR "GS_ROOT 未定义；请通过 -DGS_ROOT=<ghostscript 安装路径> 传入")
endif()

# Ghostscript 的头文件
include_directories(${GS_ROOT}/include)

# 如果定义了 CMAKE_SYSROOT，就把 sysroot 下的头文件目录也加进来
if(DEFINED CMAKE_SYSROOT)
  include_directories(SYSTEM ${CMAKE_SYSROOT}/usr/include)
endif()

# Ghostscript 的库目录
link_directories(${GS_ROOT}/lib)

add_library(pdf2pclm SHARED pdf2pclm.c)
target_link_libraries(pdf2pclm PRIVATE gs)

# 去掉 lib 前缀，输出 pdf2pclm.so
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
