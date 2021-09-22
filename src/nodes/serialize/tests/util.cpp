#include <fstream>
#include <exception>
#include <string>

#include "util.h"
#include "test_config.h"

using namespace std::literals;

constexpr auto get_test_data_path() {
    return TEST_DATA_PATH;
}

std::vector<unsigned char> get_data_from_file(const std::filesystem::path& path) {
    auto full_path = get_test_data_path() / path;

    std::ifstream fp(full_path, std::ios::binary);
    if (!fp) {
        throw std::logic_error("Failed to open file: `"s + full_path.c_str() + "`.");
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
