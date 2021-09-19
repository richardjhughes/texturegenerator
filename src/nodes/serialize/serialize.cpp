#include <sail-c++/sail-c++.h>

#include "serialize.h"
#include "image_format.h"
#include "nodes/shared/graph/sockets/binary_stream.h"

namespace texturegenerator::nodes::serialize {
    std::optional<serialize::socket_list> serialize::run(glm::vec4,
                                                         uint32_t frame_width, uint32_t frame_height,
                                                         const shared::graph::parameters& parameters,
                                                         const socket_list&) noexcept
    {
        serialize::socket_list sockets;

        auto image_format_parameter = parameters.get<uint32_t>("image_format");
        if (!image_format_parameter) {
            return {};
        }

        //sail::image image(nullptr, SailPixelFormat::SAIL_PIXEL_FORMAT_BPP48, 100, 100);

        std::vector<std::byte> image_data;

        auto frame_size { frame_width * frame_height };
        auto pixel_count { frame_size * 4 };

        // RGBA
        image_data.resize(pixel_count);

        for (auto i {0u}; i < frame_size; i += 4) {
            image_data[i + 0] = static_cast<std::byte>(serialize::default_color.r);
            image_data[i + 1] = static_cast<std::byte>(serialize::default_color.g);
            image_data[i + 2] = static_cast<std::byte>(serialize::default_color.b);
            image_data[i + 3] = static_cast<std::byte>(serialize::default_color.a);
        }

        shared::graph::sockets::binary_stream s;
        s.set_data(image_data);

        sockets.push_back(s.get_socket());

        return sockets;
    }
}
