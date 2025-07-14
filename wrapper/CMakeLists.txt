cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR "GS_ROOT 未定义；请通过 -DGS_ROOT=<ghostscript 安装路径> 传入")
endif()

# 把 GS_ROOT/include 下的所有一级子目录都加入搜索路径
include_directories(${GS_ROOT}/include)
file(GLOB GS_SUBDIRS RELATIVE "${GS_ROOT}/include" "${GS_ROOT}/include/*")
foreach(sub ${GS_SUBDIRS})
  if(IS_DIRECTORY "${GS_ROOT}/include/${sub}")
    include_directories("${GS_ROOT}/include/${sub}")
  endif()
endforeach()

# 链接 libgs.so
link_directories(${GS_ROOT}/lib)
add_library(pdf2pclm SHARED pdf2pclm.c)
target_link_libraries(pdf2pclm PRIVATE gs)

# 去掉 lib 前缀
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
