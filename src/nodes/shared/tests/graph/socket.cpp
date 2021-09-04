#include <vector>
#include <future>
#include <atomic>

#include "catch2/catch.hpp"
#include "nodes/shared/graph/socket.h"
#include "nodes/shared/graphics/color.h"

using namespace texturegenerator::shared::graph;
using namespace texturegenerator::shared;

//////////
/// write(T)
//////////

TEST_CASE("write(T) - writes data - writes successfully", "[shared/graph/socket]") {
    socket s;

    std::vector<graphics::color> expected {
        { 1, 2, 3, 4, },
    };

    s.write(expected);

    auto result = s.read<std::vector<graphics::color>>();

    REQUIRE(result);
    REQUIRE(expected == result);
}

TEST_CASE("write(T) - writes data in multiple threads - writes successfully", "[shared/graph/socket]") {
    socket s;

    std::vector<graphics::color> expected {
        { 1, 2, 3, 4, },
    };

    std::atomic_bool keep_reading {true};

    auto write_data = [&s, expected](){
        for (auto i {0}; i < 100000; ++i) {
            s.write(expected);
        }
    };

    auto read_data = [&s, &keep_reading, expected](){
        while (keep_reading) {
            auto result = s.read<std::vector<graphics::color>>();
            REQUIRE(result);
            REQUIRE(expected == result);
        }
    };

    auto f1 = std::async(std::launch::async, write_data);
    auto f2 = std::async(std::launch::async, write_data);
    auto f3 = std::async(std::launch::async, write_data);

    auto reading_future = std::async(std::launch::async, read_data);

    f1.wait();
    f2.wait();
    f3.wait();

    keep_reading = false;

    reading_future.wait();
}

//////////
/// read
//////////

TEST_CASE("read - reads data - reads successfully", "[shared/graph/socket]") {
    socket s;

    std::vector<graphics::color> expected {
        { 1, 2, 3, 4, },
    };

    s.write(expected);

    auto result = s.read<std::vector<graphics::color>>();

    REQUIRE(result);
    REQUIRE(expected == result);
}

TEST_CASE("read - reads data not written - returns default value", "[shared/graph/socket]") {
    socket s;

    auto result = s.read<std::vector<graphics::color>>();

    REQUIRE(result);
    REQUIRE(result == std::vector<graphics::color>());
}

TEST_CASE("read - reads data type not written - returns error", "[shared/graph/socket]") {
    socket s;

    s.write(std::vector<graphics::color>());

    auto result = s.read<std::vector<uint8_t>>();

    REQUIRE_FALSE(result);
}

TEST_CASE("read - reads data in multiple threads - reads successfully", "[shared/graph/socket]") {
    socket s;

    std::vector<graphics::color> expected {
        { 1, 2, 3, 4, },
    };

    std::atomic_bool keep_writing {true};

    auto write_data = [&s, &keep_writing, expected](){
        while (keep_writing) {
            s.write(expected);
        }
    };

    std::mutex mutex;

    auto read_data = [&s, &mutex, expected](){
        for (auto i {0}; i < 10000; ++i) {
            auto result = s.read<std::vector<graphics::color>>();

            // Catch2 macros are not thread safe
            // See: https://github.com/catchorg/Catch2/blob/devel/docs/limitations.md#thread-safe-assertions
            std::scoped_lock<std::mutex> lock(mutex);

            REQUIRE(result);
            REQUIRE(expected.size() == result->size());
            INFO(std::to_string(expected[0].r) + " : " + std::to_string(result->at(0).r));
            REQUIRE(expected[0].r == result->at(0).r);
            REQUIRE(expected[0].g == result->at(0).g);
            REQUIRE(expected[0].b == result->at(0).b);
            REQUIRE(expected[0].a == result->at(0).a);
        }
    };

    // avoid read errors by writing a value before we read
    s.write(expected);

    auto f1 = std::async(std::launch::async, read_data);
    auto f2 = std::async(std::launch::async, read_data);
    auto f3 = std::async(std::launch::async, read_data);

    auto writing_future = std::async(std::launch::async, write_data);

    f1.wait();
    f2.wait();
    f3.wait();

    keep_writing = false;

    writing_future.wait();
}
