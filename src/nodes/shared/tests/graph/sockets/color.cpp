#include "catch2/catch.hpp"
#include "nodes/shared/graph/sockets/color.h"

using namespace texturegenerator::shared::graph::sockets;

//////////
/// constructor
//////////

TEST_CASE("constructor - frame width is 0 - throws error", "[shared/graph/factory/sockets]") {
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

TEST_CASE("constructor - frame height is 0 - throws error", "[shared/graph/factory/sockets]") {
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

TEST_CASE("constructor - valid arguments - no error", "[shared/graph/factory/sockets]") {
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

TEST_CASE("constructor - valid frame width - sets frame width", "[shared/graph/factory/sockets]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_width();

    REQUIRE(width == result);
}

TEST_CASE("constructor - valid frame height - sets frame height", "[shared/graph/factory/sockets]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_height();

    REQUIRE(height == result);
}

TEST_CASE("constructor - constructs socket - correct size", "[shared/graph/factory/sockets]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto& socket = c.get_socket();

    auto colors = socket.read<color::type>();
    REQUIRE(colors);

    auto result = colors->size();

    auto expected = width * height;

    REQUIRE(expected == result);
}

//////////
/// get_frame_width
//////////

TEST_CASE("get_frame_width - gets frame width", "[shared/graph/factory/sockets]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_width();

    REQUIRE(width == result);
}

//////////
/// get_frame_height
//////////

TEST_CASE("get_frame_height - gets frame height", "[shared/graph/factory/sockets]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto result = c.get_frame_height();

    REQUIRE(height == result);
}

//////////
/// get_socket
//////////

TEST_CASE("get_socket - gets socket", "[shared/graph/factory/sockets]") {
    auto width {32u};
    auto height {64u};

    color c(width, height);

    auto& socket = c.get_socket();

    auto result = socket.read<color::type>();

    REQUIRE(result->size() > 0);
}
