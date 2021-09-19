#include <filesystem>
#include <iostream>

#include "serialize.h"
#include "image_format.h"
#include "nodes/shared/apis/image/image.h"
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

        auto frame_size { frame_width * frame_height };

        std::vector<shared::graphics::color> image_data;
        image_data.resize(frame_size);

        std::fill(image_data.begin(), image_data.end(), serialize::default_color);

        auto serialized_data = shared::apis::image::serialize_image(image_data, frame_width, frame_height);
        if (!serialized_data) {
            return {};
        }

        shared::graph::sockets::binary_stream s;
        s.set_data(*serialized_data);

        sockets.push_back(s.get_socket());

        return sockets;
    }
}
