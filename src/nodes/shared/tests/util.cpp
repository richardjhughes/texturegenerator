#include <fstream>
#include <exception>
#include <string>

#include "util.h"

using namespace std::literals;

std::vector<unsigned char> get_data_from_file(const std::filesystem::path& path) {
    std::ifstream fp(path, std::ios::binary);
    if (!fp) {
        throw std::logic_error("Failed to open file: `"s + path.c_str() + "`.");
    }

    fp.seekg(0, fp.end);
    auto length = fp.tellg();

    fp.seekg(0, fp.beg);

    std::vector<unsigned char> data;
    data.reserve(length);

    data.insert(data.begin(),
                std::istream_iterator<unsigned char>(fp),
                std::istream_iterator<unsigned char>());

    return data;
}
