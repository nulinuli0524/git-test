cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR "GS_ROOT 未定义；请通过 -DGS_ROOT=<ghostscript 安装路径> 传入")
endif()

# 把 Ghostscript 的所有 include 子目录都加进来
file(GLOB_RECURSE GS_HEADERS "${GS_ROOT}/include/*.h")
get_filename_component(GS_INCLUDE_DIR "${GS_ROOT}/include" ABSOLUTE)
include_directories(
  ${GS_INCLUDE_DIR}
  ${GS_INCLUDE_DIR}/ghostscript
)

# 链接 libgs.so
link_directories(${GS_ROOT}/lib)

add_library(pdf2pclm SHARED pdf2pclm.c)
target_link_libraries(pdf2pclm PRIVATE gs)
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
