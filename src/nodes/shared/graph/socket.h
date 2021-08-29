#pragma once

#include <variant>
#include <vector>
#include <mutex>
#include <optional>

#include "nodes/shared/graphics/color.h"

namespace texturegenerator::shared::graph {
    // A socket represents an input or output from a node containing
    // some form of data. A node can accept sockets as inputs and/or
    // outputs. This class is thread safe.
    class socket
    {
    public:
        // write a copy of the data to the socket
        template <typename T>
        void write(T data) noexcept {
            std::scoped_lock<std::mutex> l(this->_mutex);

            this->_data = data;
        }

        // reads a copy of the data from the socket
        template <typename T>
        std::optional<T> read() const noexcept {
            std::scoped_lock<std::mutex> l(this->_mutex);

            try {
                T t = std::get<T>(this->_data);
                return t;
            }
            catch (const std::exception&) {
                return {};
            }
        }

    private:
        mutable std::mutex _mutex;

        // only types in this variant are valid values for sockets to read/write
        std::variant<
            std::vector<graphics::color>,
            std::vector<uint8_t>
        > _data;
    };
}
