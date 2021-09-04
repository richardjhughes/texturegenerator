#include "catch2/catch.hpp"
#include "nodes/color/color.h"

using namespace texturegenerator::nodes::color;

//////////
/// run
//////////

TEST_CASE("run - valid type - does not return error", "[shared/graph/factory]") {
    auto type = node_types::color;

    factory f;

    auto result = f.register_node(type, [](){ return std::make_shared<test_node>(); });
    REQUIRE(result);
}
