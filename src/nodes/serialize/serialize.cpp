#include <sail-c++/sail-c++.h>

#include "serialize.h"
#include "image_format.h"

namespace texturegenerator::nodes::serialize {
    std::optional<serialize::socket_list> serialize::run(glm::vec4,
                                                         uint32_t, uint32_t,
                                                         const shared::graph::parameters& parameters,
                                                         const socket_list&) noexcept
    {
        serialize::socket_list sockets;

        auto image_format_parameter = parameters.get<uint32_t>("image_format");
        if (!image_format_parameter) {
            return {};
        }

        sail::image image("");

        return sockets;
    }
}
