#include <filesystem>
#include <iostream>

#include "serialize.h"
#include "image_format.h"
#include "nodes/shared/apis/image/image.h"
#include "nodes/shared/graph/sockets/binary_stream.h"
#include "nodes/shared/graph/sockets/color_channel.h"

namespace texturegenerator::nodes::serialize {
    std::optional<serialize::socket_list> serialize::run(glm::vec4,
                                                         uint32_t frame_width, uint32_t frame_height,
                                                         const shared::graph::parameters& parameters,
                                                         const socket_list& input_sockets) noexcept {
        serialize::socket_list sockets;

        auto image_format_parameter = parameters.get<uint32_t>("image_format");
        if (!image_format_parameter) {
            return {};
        }

        auto frame_size { frame_width * frame_height };

        std::vector<shared::graphics::color> image_data;
        image_data.resize(frame_size);

        if (input_sockets.size() == 4) {
            shared::graph::sockets::color_channel red_channel(input_sockets[0]);
            shared::graph::sockets::color_channel green_channel(input_sockets[1]);
            shared::graph::sockets::color_channel blue_channel(input_sockets[2]);
            shared::graph::sockets::color_channel alpha_channel(input_sockets[3]);

            auto red_data = red_channel.get_data();
            auto green_data = green_channel.get_data();
            auto blue_data = blue_channel.get_data();
            auto alpha_data = alpha_channel.get_data();

            if (red_data.size() != frame_size ||
                green_data.size() != frame_size ||
                blue_data.size() != frame_size ||
                alpha_data.size() != frame_size) {
                std::cout << "Socket input data not equal to frame size: " << frame_size << '\n';
                return {};
            }

            for (auto i {0u}; i < frame_size; ++i) {
                shared::graphics::color c {
                    red_data[i], green_data[i], blue_data[i], alpha_data[i],
                };

                image_data[i] = c;
            }
        }
        else if (input_sockets.empty()) {
            std::fill(image_data.begin(), image_data.end(), serialize::default_color);
        }
        else {
            std::cout << "Invalid number of input sockets. Expected 4. Actual: " << input_sockets.size() << '\n';
            return {};
        }

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
