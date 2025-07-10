#include <iostream>

extern "C" int convert(const char*, const char*);

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.pdf> <output.pclm>\n";
        return 1;
    }
    const char* in = argv[1];
    const char* out = argv[2];
    std::cout << "Converting " << in << " → " << out << "\n";
    int ret = convert(in, out);
    if (ret == 0) {
        std::cout << "Conversion successful\n";
    } else {
        std::cerr << "Conversion failed, code=" << ret << "\n";
    }
    return ret;
}
