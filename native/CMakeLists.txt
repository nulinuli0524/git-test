cmake_minimum_required(VERSION 3.10)
project(gs_napi_demo)

# 必需：外部传入 Ghostscript/CMakeLists.txt` 下能直接工作的完整示例，去掉了所有多余的分隔符和非 CMake 语法。按需修改其中的 `GS_ROOT` 路径即可。

```cmake
cmake_minimum_required(VERSION 3.10)
project(gs_napi_demo)

# 必需：外部传入 Ghostscript 安装根目录
if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR "GS_ROOT is not defined. Pass -DGS_ROOT=/path/to/ghostpdl/install")
endif()

# 查找 Ghostscript 头文件
find_path(
  GHOSTSCRIPT_INCLUDE
  NAMES iapi.h
  PATH 安装根目录
if(NOT DEFINED GS_ROOT)
  message(FATAL_ERROR "GS_ROOT is not defined. Pass -DGS_ROOT=/path/to/ghostpdl/install")
endif()

# 查找 Ghostscript 头文件
find_path(
  GHOSTSCRIPT_INCLUDE
  NAMES iapi.h
  PATHS
    ${GS_ROOT}/include/ghostscript
    /usr/include/ghostscript
  REQUIRED
)

# 查找 Ghostscript 动态库 libgs.so
find_library(
  GHOSTSCRIPT_LIBRARY
  NAMES gs
  PATHS
    ${GS_ROOT}/S
    ${GS_ROOT}/include/ghostscript
    /usr/include/ghostscript
  REQUIRED
)

# 查找 Ghostscript 动态库 libgs.so
find_library(
  GHOSTSCRIPT_LIBRARY
  NAMES gs
  PATHS
    ${GS_ROOT}/lib
    /usr/lib
    /usr/lib/x86_64-linux-gnu
  REQUIRED
)

# 查找 Node-API 头文件 node_api.h
find_path(
  NODE_API_INCLUDE
  NAMES node_api.h
  PATHS
    /usr/include
    /usr/include/node
    /usr/local/includelib
    /usr/lib
    /usr/lib/x86_64-linux-gnu
  REQUIRED
)

# 查找 Node-API 头文件 node_api.h
find_path(
  NODE_API_INCLUDE
  NAMES node_api.h
  PATHS
    /usr/include
    /usr/include/node
    /usr/local/include
  REQUIRED
)

# 包含头文件搜索目录
include_directories(
  ${GHOSTSCRIPT_INCLUDE}
  ${NODE_API_INCLUDE}
)

# 定义 N-API 封装库
add_library(gs_napi SHARED gs_napi.cpp)

# 链接 Ghostscript 的核心库
target_link_libraries(gs_napi PRIVATE ${GHOSTSCRIPT_LIBRARY})

# 强制输出名称为 libgs_napi.so
set_target_properties(gs_napi PROPERTIES
  OUTPUT_NAME "gs_napi"
)
