#pragma once

#include <memory>
#include <functional>
#include <unordered_map>
#include <optional>

#include "node.h"

namespace texturegenerator::shared::graph {
    class factory {
    public:
        factory() = default;
        virtual ~factory() = default;
        factory(const factory&) = delete;
        factory(factory&&) = default;

        // Registers a node
        // type: the node type
        // functor: a functor that returns a new instance of the node indicated by `type`
        bool register_node(node_types type, std::function<std::shared_ptr<node>(void)> functor) noexcept;

        [[nodiscard]]
        std::optional<std::shared_ptr<node>> create(node_types type) noexcept;

    private:
        std::unordered_map<node_types, std::function<std::shared_ptr<node>(void)>> _registered_nodes;
    };
}
