#pragma once

#include <cstdint>
#include <exception>

#include "nodes/shared/graph/socket.h"

namespace texturegenerator::shared::graph::sockets {
    // Represents the color socket. This wraps a socket of type
    // `std::vector<graphics::color>`.
    class color final {
    public:
        using type = std::vector<graphics::color>;

        color(std::uint32_t frame_width, std::uint32_t frame_height)
            : _frame_width(frame_width),
              _frame_height(frame_height) {
            if (this->_frame_width == 0) {
                throw std::invalid_argument("`frame_width` is 0.");
            }

            if (this->_frame_height == 0) {
                throw std::invalid_argument("`frame_height` is 0.");
            }

            this->construct_socket();
        }

        color(std::uint32_t frame_width, std::uint32_t frame_height, std::shared_ptr<socket> socket)
            : _frame_width(frame_width),
              _frame_height(frame_height),
              _socket(std::move(socket)) {
            if (this->_frame_width == 0) {
                throw std::invalid_argument("`frame_width` is 0.");
            }

            if (this->_frame_height == 0) {
                throw std::invalid_argument("`frame_height` is 0.");
            }
        }

        uint32_t get_frame_width() const noexcept {
            return this->_frame_width;
        }

        uint32_t get_frame_height() const noexcept {
            return this->_frame_height;
        }

        const std::shared_ptr<socket>& get_socket() const noexcept {
            return this->_socket;
        }

        // returns the color data from the socket
        // if the socket does not contain color data,
        // an assert is triggered
        type get_data() const noexcept {
            auto data = this->_socket->read<type>();
            assert(data);

            return *data;
        }

        // fills the socket with the color
        void set_color(const graphics::color& color) noexcept;

    private:
        std::uint32_t _frame_width {0};
        std::uint32_t _frame_height {0};
        std::shared_ptr<socket> _socket;

        // allocates the needed data in the socket
        void construct_socket() noexcept;
    };
}
