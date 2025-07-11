add_library(gs_napi SHARED gs_napi.cpp)
set_target_properties(gs_napi PROPERTIES
  PREFIX ""            # 无 lib 前缀
  OUTPUT_NAME "gs_napi"
)
