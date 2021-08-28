#pragma once

#include "nodes/shared/graph/node.h"
#include "nodes/shared/graphics/color.h"

namespace texturegenerator::nodes::color {
    class color final : public shared::graph::node {
    public:
        // Returns a constant color in a frame sized `frame_width * frame_height`
        // as a constant color is generated, the origin is ignored
        // Expected input sockets:
        // * None
        // Output sockets:
        // * The generated color
        [[nodiscard]]
        socket_list run(glm::vec4 origin, uint32_t frame_width, uint32_t frame_height, const socket_list& sockets) override;
    };
}
