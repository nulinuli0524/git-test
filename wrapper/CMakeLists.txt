cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

# 必须通过 -DGS_ROOT=<ghostscript 安装根目录> 传入
if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR "GS_ROOT 未定义；请通过 -DGS_ROOT=... 传入 Ghostscript 安装根路径")
endif()

# 把 Ghostscript 的头文件目录加入
include_directories(${GS_ROOT}/include)

# 使用 Ghostscript 库所在的 lib 目录
link_directories(${GS_ROOT}/lib)

add_library(pdf2pclm SHARED pdf2pclm.c)
target_link_libraries(pdf2pclm PRIVATE gs)

# 去掉 lib 前缀，输出 pdf2pclm.so
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
