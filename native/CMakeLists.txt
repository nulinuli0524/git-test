# native/CMakeLists.txt

# 1. 必须要的 CMake 版本和项目名
cmake_minimum_required(VERSION 3.10)
project(gs_napi_demo LANGUAGES C CXX)

# 2. 找到 Ghostscript 的头文件和库
find_path(GS_INC
  NAMES iapi.h
  PATHS
    /usr/include/ghostscript
    /usr/local/include/ghostscript
    /usr/include
  REQUIRED
)
find_library(GS_LIB
  NAMES gs
  PATHS /usr/lib /usr/lib/x86_64-linux-gnu
  REQUIRED
)

# 3. 找到 Node-API 的头文件
find_path(NODE_API_INC
  NAMES node_api.h
  PATHS
    /usr/include/node
    /usr/local/include/node
  REQUIRED
)

# 4. 把头文件目录都加入进来
include_directories(
  ${GS_INC}
  ${NODE_API_INC}
)

# 5. 编译生成 gs_napi.so（不加 lib 前缀）
add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi PRIVATE ${GS_LIB})

set_target_properties(gs_napi PROPERTIES
  PREFIX ""            # 去掉默认 lib 前缀
  OUTPUT_NAME "gs_napi"
)
