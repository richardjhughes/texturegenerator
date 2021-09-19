#pragma once

#include <vector>
#include <filesystem>

std::vector<unsigned char> get_data_from_file(const std::filesystem::path& path);
