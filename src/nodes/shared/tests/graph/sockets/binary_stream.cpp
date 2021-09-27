#include "catch2/catch.hpp"
#include "nodes/shared/graph/sockets/binary_stream.h"

using namespace texturegenerator::shared;
using namespace texturegenerator::shared::graph::sockets;

//////////
/// constructor (socket)
//////////

TEST_CASE("constructor (socket) - null socket - throws error", "[shared/graph/factory/sockets/binary_stream]") {
    std::shared_ptr<graph::socket> socket;

    try {
        binary_stream s(socket);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor (socket) - valid socket - sets socket", "[shared/graph/factory/sockets/binary_stream]") {
    auto socket = std::make_shared<graph::socket>();

    binary_stream s(socket);

    auto result = s.get_socket();

    REQUIRE(socket == result);
}

//////////
/// get_data
//////////

TEST_CASE("get_data - gets data", "[shared/graph/factory/sockets/binary_stream]") {
    std::vector<std::byte> data { (std::byte)0x00, (std::byte)0x01, (std::byte)0x02, (std::byte)0x03, (std::byte)0x04, };

    auto socket = std::make_shared<graph::socket>();
    socket->write(data);

    binary_stream s(socket);

    auto result = s.get_data();

    REQUIRE(data == result);
}

//////////
/// get_data
//////////

TEST_CASE("set_data - valid data - sets data", "[shared/graph/factory/sockets/binary_stream]") {
    std::vector<std::byte> data { (std::byte)0x00, (std::byte)0x01, (std::byte)0x02, (std::byte)0x03, (std::byte)0x04, };

    binary_stream s;

    s.set_data(data);
    auto result = s.get_data();

    REQUIRE(data == result);
}
