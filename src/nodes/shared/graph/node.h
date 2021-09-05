#pragma once

#include <vector>
#include <memory>
#include <optional>
#include <glm/vec4.hpp>

#include "parameters.h"
#include "socket.h"
#include "node_types.h"

namespace texturegenerator::shared::graph {
    class node
    {
    public:
        using socket_list = std::vector<std::shared_ptr<socket>>;

        node() = default;
        virtual ~node() = default;
        node(const node&) = default;
        node(node&&) = default;

        // Runs the node
        // origin: the point in space where the algorithm should compute from
        // frame_width: the number of pixels wide to compute
        // frame_height: the number of pixels height to compute
        // sockets: the input sockets
        // returns: the output sockets
        [[nodiscard]]
        virtual std::optional<socket_list> run(glm::vec4 origin,
                                               uint32_t frame_width, uint32_t frame_height,
                                               const parameters& parameters,
                                               const socket_list& sockets) noexcept = 0;

        [[nodiscard]]
        virtual node_types get_node_type() noexcept = 0;
    };
}
