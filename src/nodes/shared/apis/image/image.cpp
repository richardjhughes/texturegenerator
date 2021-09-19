#include <fstream>
#include <filesystem>
#include <iostream>
#include <sail-c++/sail-c++.h>

#include "image.h"

namespace texturegenerator::shared::apis::image {
    std::optional<std::vector<std::byte>> serialize_image(std::vector<graphics::color>& pixels,
                                                          uint32_t width, uint32_t height) noexcept {
        if (pixels.empty()) {
            return {};
        }

        auto total_size { width * height };

        if (pixels.size() != total_size) {
            return {};
        }

        sail::image image(pixels.data(),
                          SailPixelFormat::SAIL_PIXEL_FORMAT_BPP32_RGBA,
                          width, height);


        auto temp_path = std::filesystem::temp_directory_path() / "texturegenerator";
        std::filesystem::create_directories(temp_path);

        temp_path /= "temp.png";

        std::cout << "Saving image to path: `" << temp_path << "`...\n";

        sail::image_output output;
        if (auto result = output.save(temp_path.c_str(), image); result != SailStatus::SAIL_OK) {
            std::cout << "Error saving image to path: `" << temp_path << "` with error: "
                      << result << '\n';
            return {};
        }

        std::vector<std::byte> serialized_data;

        std::ifstream fp(temp_path, std::ios::binary);
        if (!fp) {
            std::cout << "Failed to open file: `" << temp_path.c_str() << "`.\n";
        }

        fp.seekg(0, fp.end);
        auto length = fp.tellg();

        fp.seekg(0, fp.beg);

        std::vector<unsigned char> data;
        data.reserve(length);

        data.insert(data.begin(),
                    std::istream_iterator<unsigned char>(fp),
                    std::istream_iterator<unsigned char>());

        for (auto d : data) {
            serialized_data.push_back(static_cast<std::byte>(d));
        }

        return serialized_data;
    }
}
