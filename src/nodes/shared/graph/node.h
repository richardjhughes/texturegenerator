#pragma once

#include <vector>
#include <memory>

#include "socket.h"

namespace texturegenerator::shared::graph {
    class node
    {
    public:
        using socket_list = std::vector<std::shared_ptr<socket>>;

        // Runs the node
        // origin: the point in space where the algorithm should compute from
        // frame_width: the number of pixels wide to compute
        // frame_height: the number of pixels hight to compute
        // sockets: the input sockets
        // returns: the output sockets
        [[nodiscard]]
        virtual socket_list run(int32_t origin, uint32_t frame_width, uint32_t frame_height, const socket_list& sockets) = 0;
    };
}
