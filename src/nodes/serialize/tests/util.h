#pragma once

#include <vector>
#include <filesystem>

constexpr auto get_test_data_path();

std::vector<unsigned char> get_data_from_file(const std::filesystem::path& path);
