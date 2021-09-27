#include "catch2/catch.hpp"
#include "nodes/shared/graph/sockets/color.h"

using namespace texturegenerator::shared;
using namespace texturegenerator::shared::graph::sockets;

//////////
/// constructor (uint32_t, uint32_t)
//////////

TEST_CASE("constructor (uint32_t, uint32_t) - frame width is 0 - throws error", "[shared/graph/factory/sockets/color]") {
    auto width {0u};
    auto height {32u};

    try {
        color c(width, height);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor (uint32_t, uint32_t) - frame height is 0 - throws error", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {0u};

    try {
        color c(width, height);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor (uint32_t, uint32_t) - valid arguments - no error", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    try {
        color c(width, height);
    }
    catch (const std::exception&) {
        FAIL("Exception thrown.");
        return;
    }

    SUCCEED("Exception not thrown.");
}

TEST_CASE("constructor (uint32_t, uint32_t) - valid frame width - sets frame width", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_width();

    REQUIRE(width == result);
}

TEST_CASE("constructor (uint32_t, uint32_t) - valid frame height - sets frame height", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_height();

    REQUIRE(height == result);
}

TEST_CASE("constructor (uint32_t, uint32_t) - constructs socket - correct size", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto socket = c.get_socket();
    REQUIRE(socket);

    auto colors = socket->read<color::type>();
    REQUIRE(colors);

    auto result = colors->size();

    auto expected = width * height;

    REQUIRE(expected == result);
}

//////////
/// constructor (uint32_t, uint32_t, socket)
//////////

TEST_CASE("constructor (uint32_t, uint32_t, socket) - frame width is 0 - throws error", "[shared/graph/factory/sockets/color]") {
    auto width {0u};
    auto height {32u};
    auto socket = std::make_shared<graph::socket>();

    std::vector<graphics::color> colors { graphics::colors::black };
    socket->write(colors);

    try {
        color c(width, height, socket);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor (uint32_t, uint32_t, socket) - frame height is 0 - throws error", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {0u};
    auto socket = std::make_shared<graph::socket>();

    std::vector<graphics::color> colors { graphics::colors::black };
    socket->write(colors);

    try {
        color c(width, height, socket);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor (uint32_t, uint32_t, socket) - valid arguments - no error", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};
    auto socket = std::make_shared<graph::socket>();

    std::vector<graphics::color> colors { graphics::colors::black };
    socket->write(colors);

    try {
        color c(width, height, socket);
    }
    catch (const std::exception&) {
        FAIL("Exception thrown.");
        return;
    }

    SUCCEED("Exception not thrown.");
}

TEST_CASE("constructor (uint32_t, uint32_t, socket) - valid frame width - sets frame width", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};
    auto socket = std::make_shared<graph::socket>();

    std::vector<graphics::color> colors { graphics::colors::black };
    socket->write(colors);

    color c(width, height, socket);

    auto result = c.get_frame_width();

    REQUIRE(width == result);
}

TEST_CASE("constructor (uint32_t, uint32_t, socket) - valid frame height - sets frame height", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};
    auto socket = std::make_shared<graph::socket>();

    std::vector<graphics::color> colors { graphics::colors::black };
    socket->write(colors);

    color c(width, height, socket);

    auto result = c.get_frame_height();

    REQUIRE(height == result);
}

TEST_CASE("constructor (uint32_t, uint32_t, socket) - valid socket - sets socket", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};
    auto socket = std::make_shared<graph::socket>();

    std::vector<graphics::color> colors { graphics::colors::black };
    socket->write(colors);

    color c(width, height, socket);

    auto result = c.get_socket();
    REQUIRE(result);

    auto resulting_data = result->read<decltype(colors)>();
    REQUIRE(colors == resulting_data);
}

//////////
/// get_frame_width
//////////

TEST_CASE("get_frame_width - gets frame width", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_width();

    REQUIRE(width == result);
}

//////////
/// get_frame_height
//////////

TEST_CASE("get_frame_height - gets frame height", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_height();

    REQUIRE(height == result);
}

//////////
/// get_socket
//////////

TEST_CASE("get_socket - gets socket", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto socket = c.get_socket();
    REQUIRE(socket);

    auto result = socket->read<color::type>();

    REQUIRE(result->size() > 0);
}

//////////
/// get_data
//////////

TEST_CASE("get_data - gets data from socket", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_data();

    REQUIRE(result.size() > 0);
}

//////////
/// set_color
//////////

TEST_CASE("set_color - set color - sets color", "[shared/graph/factory/sockets/color]") {
    auto width {32u};
    auto height {64u};

    auto expected = graphics::colors::red;

    color c(width, height);
    c.set_color(expected);

    auto result = c.get_data();

    for (const auto& result_color : result) {
        REQUIRE(expected == result_color);
    }
}

