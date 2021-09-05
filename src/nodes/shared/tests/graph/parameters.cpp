#include <vector>
#include <future>
#include <atomic>

#include "catch2/catch.hpp"
#include "nodes/shared/graph/parameters.h"
#include "nodes/shared/graphics/color.h"

using namespace texturegenerator::shared::graph;
using namespace texturegenerator::shared;

//////////
/// set(T)
//////////

TEST_CASE("set(T) - sets data - sets successfully", "[shared/graph/socket]") {
    parameters p;

    auto key = "my key";

    graphics::color expected { 1, 2, 3, 4, };

    p.set(key, expected);

    auto result = p.get<decltype(expected)>(key);

    REQUIRE(result);
    REQUIRE(expected == result);
}

//////////
/// get
//////////

TEST_CASE("get - unknown key - returns error", "[shared/graph/socket]") {
    parameters p;

    auto key = "my key";

    graphics::color expected { 1, 2, 3, 4, };

    p.set(key, expected);

    auto result = p.get<decltype(expected)>("unknown key");

    REQUIRE_FALSE(result);
}

TEST_CASE("get - known key, but invalid type - returns error", "[shared/graph/socket]") {
    parameters p;

    auto key = "my key";

    graphics::color expected { 1, 2, 3, 4, };

    p.set(key, expected);

    auto result = p.get<int>(key);

    REQUIRE_FALSE(result);
}

TEST_CASE("get - valid inputs - gets value", "[shared/graph/socket]") {
    parameters p;

    auto key = "my key";

    graphics::color expected { 1, 2, 3, 4, };

    p.set(key, expected);

    auto result = p.get<decltype(expected)>(key);

    REQUIRE(result);
    REQUIRE(expected == result);
}
