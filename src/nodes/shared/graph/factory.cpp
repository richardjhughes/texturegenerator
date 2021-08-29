#include "factory.h"

namespace texturegenerator::shared::graph {
    bool factory::register_node(node_types type, std::function<std::shared_ptr<node>(void)> functor) noexcept {
        if (this->_registered_nodes.find(type) != this->_registered_nodes.end()) {
            return false;
        }

        this->_registered_nodes[type] = std::move(functor);

        return true;
    }

    std::optional<std::shared_ptr<node>> factory::create(node_types type) noexcept {
        if (this->_registered_nodes.find(type) == this->_registered_nodes.end()) {
            return {};
        }

        return this->_registered_nodes[type]();
    }
}
