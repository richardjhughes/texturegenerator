#include "color.h"
#include "nodes/shared/graph/sockets/color.h"

namespace texturegenerator::nodes::color {
    std::optional<color::socket_list> color::run(glm::vec4,
                                                 uint32_t frame_width, uint32_t frame_height,
                                                 const shared::graph::parameters& parameters,
                                                 const socket_list&) noexcept
    {
        color::socket_list sockets;

        auto color_parameter = parameters.get<shared::graphics::color>("color");
        if (!color_parameter) {
            return {};
        }

        shared::graph::sockets::color color_socket(frame_width, frame_height);
        color_socket.set_color(*color_parameter);

        sockets.push_back(color_socket.get_socket());

        return sockets;
    }
}
