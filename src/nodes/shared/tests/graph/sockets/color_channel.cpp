#include "catch2/catch.hpp"
#include "nodes/shared/graph/sockets/color_channel.h"

using namespace texturegenerator::shared;
using namespace texturegenerator::shared::graphics;
using namespace texturegenerator::shared::graph::sockets;

//////////
/// constructor (socket)
//////////

TEST_CASE("constructor (socket) - null socket - throws error", "[shared/graph/factory/sockets/color_channel]") {
    std::shared_ptr<graph::socket> socket;

    try {
        color_channel s(socket);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor (socket) - valid socket - sets socket", "[shared/graph/factory/sockets/color_channel]") {
    auto socket = std::make_shared<graph::socket>();

    color_channel s(socket);

    auto result = s.get_socket();

    REQUIRE(socket == result);
}

//////////
/// get_data
//////////

TEST_CASE("get_data - gets data", "[shared/graph/factory/sockets/color_channel]") {
    std::vector<uint8_t> data {
        0, 1, 2, 3, 4, 5,
    };

    auto socket = std::make_shared<graph::socket>();
    socket->write(data);

    color_channel s(socket);

    auto result = s.get_data();

    REQUIRE(data == result);
}

//////////
/// get_data
//////////

TEST_CASE("set_data - valid data - sets data", "[shared/graph/factory/sockets/color_channel]") {
    std::vector<uint8_t> data {
        0, 1, 2, 3, 4, 5,
    };

    color_channel s;

    s.set_data(data);
    auto result = s.get_data();

    REQUIRE(data == result);
}
