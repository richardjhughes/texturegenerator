#include "catch2/catch.hpp"
#include "nodes/shared/graph/sockets/color_stream.h"

using namespace texturegenerator::shared;
using namespace texturegenerator::shared::graphics;
using namespace texturegenerator::shared::graph::sockets;

//////////
/// constructor (socket)
//////////

TEST_CASE("constructor (socket) - null socket - throws error", "[shared/graph/factory/sockets]") {
    std::shared_ptr<graph::socket> socket;

    try {
        color_stream s(socket);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor (socket) - valid socket - sets socket", "[shared/graph/factory/sockets]") {
    auto socket = std::make_shared<graph::socket>();

    color_stream s(socket);

    auto result = s.get_socket();

    REQUIRE(socket == result);
}

//////////
/// get_data
//////////

TEST_CASE("get_data - gets data", "[shared/graph/factory/sockets]") {
    std::vector<color> data {
        colors::black, colors::red, colors::black, colors::red,
    };

    auto socket = std::make_shared<graph::socket>();
    socket->write(data);

    color_stream s(socket);

    auto result = s.get_data();

    REQUIRE(data == result);
}

//////////
/// get_data
//////////

TEST_CASE("set_data - valid data - sets data", "[shared/graph/factory/sockets]") {
    std::vector<color> data {
        colors::black, colors::red, colors::black, colors::red,
    };

    color_stream s;

    s.set_data(data);
    auto result = s.get_data();

    REQUIRE(data == result);
}
