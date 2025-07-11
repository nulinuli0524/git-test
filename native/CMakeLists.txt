cmake_minimum_required(VERSION 3.10)
project(gs`

---

## 三、`native/CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)
project(gs_napi_demo)

# Ghostscript 库和头
find_library(GS_LIB gs REQUIRED)
find_path(GS_INC iapi.h PATHS ${GS_ROOT}/include /usr/include/ghostscript)

# N-API_napi_demo)

# Ghostscript 库和头
find_library(GS_LIB gs REQUIRED)
find_path(GS_INC iapi.h PATHS ${GS_ROOT}/include /usr/include/ghostscript)

# N-API 头（如果需要本地测试，可安装 lib 头（如果需要本地测试，可安装 libnode-dev）
find_path(NAPI_INC node_apinode-dev）
find_path(NAPI_INC node_api.h PATHS /usr/include /usr/include/node)

include_directories(${GS_INC} ${NAPI_INC})

add_library(gs_napi SHARED gs.h PATHS /usr/include /usr/include/node)

include_directories(${GS_INC} ${NAPI_INC})

add_library(gs_napi SHARED gs_napi.cpp)
target_link_libraries(gs_napi PRIVATE ${GS_LIB})

# 输出名强制为 libgs_napi.so
set_target_properties(gs_napi PROPERTIES OUTPUT_NAME "gs_napi")
