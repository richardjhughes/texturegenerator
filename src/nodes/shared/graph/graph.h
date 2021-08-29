#pragma once

#include <memory>

#include "factory.h"

namespace texturegenerator::shared::graph {
    // A graph represents a group of nodes that are connected by
    // their sockets. There can be multiple starting nodes and
    // multiple ending nodes. A starting node is a node that has
    // either no input sockets or no nodes connected to its input
    // sockets. An ending node is a node that has either no output
    // sockets or that has no nodes connected to its output sockets.
    // As nodes are stateless, the graph will try to run the nodes
    // as parallel as it can.
    class graph
    {
    public:
        graph(std::unique_ptr<factory> factory) {
            if (!factory) {
                throw std::invalid_argument("factory is nullptr.");
            }

            this->_factory = std::move(factory);
        }
    private:
        std::unique_ptr<factory> _factory;
    };
}
