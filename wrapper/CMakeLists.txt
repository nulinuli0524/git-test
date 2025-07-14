cmake_minimum_required(VERSION 3.10)
project(pdf2pclm C)

# 编译器和链接选项会从环境变量继承
set(CMAKE_C_COMPILER   ${ENV{CC}})
set(CMAKE_C_FLAGS      "${ENV{CFLAGS}}")
set(CMAKE_SHARED_LINKER_FLAGS "${ENV{LDFLAGS}}")

# Ghostscript 头文件和库路径
include_directories(${CMAKE_SOURCE_DIR}/../ghostpdl/build_output/usr/local/ghostscript/include)

find_library(GS_LIB gs
    PATHS ${CMAKE_SOURCE_DIR}/../ghostpdl/build_output/usr/local/ghostscript/lib
)

add_library(pdf2pclm SHARED pdf2pclm.c)
target_link_libraries(pdf2pclm PRIVATE ${GS_LIB})
set_target_properties(pdf2pclm PROPERTIES PREFIX "")
