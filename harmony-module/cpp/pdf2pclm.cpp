#include <cstdio>

extern "C" void convertPdfToPcl(const char* in, const char* out) {
    std::printf("Convert %s -> %s\n", in, out);
    // 这里调用 Ghostscript API 完成真正转换
}
