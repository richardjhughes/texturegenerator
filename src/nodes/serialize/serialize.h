#pragma once

#include "nodes/shared/graph/node.h"
#include "nodes/shared/graphics/color.h"

namespace texturegenerator::nodes::serialize {
    class serialize : public shared::graph::node {
    public:
        static constexpr auto default_color = shared::graphics::colors::transparent;

        // Serializes the passed color streams into a known image format
        // NOTE: The output stream is not saved to disk. It is up to the
        // caller to save the output stream if desired.
        // Expected input sockets:
        // * R - type: ColorChannel
        // * G - type: ColorChannel
        // * B - type: ColorChannel
        // * A - type: ColorChannel
        // Output sockets:
        // * Stream - type: BinaryStream
        [[nodiscard]]
        std::optional<socket_list> run(glm::vec4 origin,
            uint32_t frame_width, uint32_t frame_height,
            const shared::graph::parameters& parameters,
            const socket_list& sockets) noexcept override;

        [[nodiscard]]
        shared::graph::node_types get_node_type() noexcept override {
            return shared::graph::node_types::serialize;
        }
    };
}
