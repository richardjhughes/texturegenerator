#include <cassert>

#include "color.h"

namespace texturegenerator::shared::graph::sockets {
    void color::construct_socket() noexcept {
        color::type color_data;

        auto needed_bytes = this->_frame_width * this->_frame_height;

        // `reserve` doesn't set the actual size of the vector, which
        // is what we need
        color_data.resize(needed_bytes);

        this->_socket = std::make_shared<socket>();
        this->_socket->write(color_data);

        // default to black
        this->set_color(graphics::colors::black);
    }

    void color::set_color(const graphics::color& color) noexcept {
        auto data = this->_socket->read<color::type>();
        assert(data && "No color data in socket.");

        std::fill(data->begin(), data->end(), color);

        this->_socket->write(*data);
    }
}
