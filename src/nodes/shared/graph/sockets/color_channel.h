#pragma once

#include <vector>
#include <memory>
#include <cstdint>
#include <cassert>

#include "nodes/shared/graph/socket.h"

namespace texturegenerator::shared::graph::sockets {
    // Represents the `ColorStream` socket. This wraps a socket of type
    // `std::vector<uint8_t>`.
    class color_channel final {
    public:
        using type = std::vector<uint8_t>;

        color_channel()
            : _socket(std::make_shared<socket>()) {
        }

        color_channel(const std::shared_ptr<socket>& socket)
            : _socket(socket) {
            if (!this->_socket) {
                throw std::invalid_argument("`socket` is nullptr.");
            }
        }

        const std::shared_ptr<socket>& get_socket() const noexcept {
            return this->_socket;
        }

        // returns the binary data from the socket
        // if the socket does not contain binary data,
        // an assert is triggered
        type get_data() const noexcept {
            auto data = this->_socket->read<type>();
            assert(data);

            return *data;
        }

        void set_data(const type& data) noexcept {
            this->_socket->write(data);
        }

    private:
        std::shared_ptr<socket> _socket;
    };
}
