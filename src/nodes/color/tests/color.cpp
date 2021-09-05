#include "catch2/catch.hpp"
#include "nodes/color/color.h"
#include "nodes/shared/graph/sockets/color.h"

using namespace texturegenerator;
using namespace texturegenerator::nodes::color;

//////////
/// get_node_type
//////////

TEST_CASE("get_node_type - returns correct value", "[nodes/color/color]") {
    color node;

    auto result = node.get_node_type();

    auto expected { shared::graph::node_types::color };

    REQUIRE(expected == result);
}

//////////
/// run
//////////

TEST_CASE("run - valid type - does not return error", "[nodes/color/color]") {
    color node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    //auto color { shared::graphics::colors::red };

    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, sockets_in);

    REQUIRE(result);
}
