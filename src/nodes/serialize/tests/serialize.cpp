#include "catch2/catch.hpp"
#include "nodes/serialize/serialize.h"

using namespace texturegenerator;
using namespace texturegenerator::nodes::serialize;

//////////
/// get_node_type
//////////

TEST_CASE("get_node_type - returns correct value", "[nodes/serialize/serialize]") {
    serialize node;

    auto result = node.get_node_type();

    auto expected { shared::graph::node_types::serialize };

    REQUIRE(expected == result);
}

//////////
/// run
//////////
