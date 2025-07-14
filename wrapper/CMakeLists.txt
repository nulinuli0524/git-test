cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR "GS_ROOT 未定义；请通过 -DGS_ROOT=<Ghostscript 安装根路径> 传入")
endif()

# Ghostscript 的公头目录
include_directories(${GS_ROOT}/include)

# Ghostscript 的 psi 子目录，包含 iapi.h、imemory.h
include_directories(${GS_ROOT}/psi)

# HarmonyOS NDK 公头（可选）
if(DEFINED CMAKE_SYSROOT)
  include_directories(SYSTEM ${CMAKE_SYSROOT}/usr/include)
endif()

# 链接 Ghostscript 库
link_directories(${GS_ROOT}/lib)
add_library(pdf2pclm SHARED pdf2pclm.c)
target_link_libraries(pdf2pclm PRIVATE gs)
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
