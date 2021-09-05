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

TEST_CASE("run - no color parameter - returns error", "[nodes/color/color]") {
    color node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };

    shared::graph::parameters parameters;
    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE_FALSE(result);
}

TEST_CASE("run - valid parameters - does not return error", "[nodes/color/color]") {
    color node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto color { shared::graphics::colors::red };

    shared::graph::parameters parameters;
    parameters.set("color", color);

    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE(result);
}

TEST_CASE("run - sets color - returns correct sockets", "[nodes/color/color]") {
    color node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto color { shared::graphics::colors::red };

    shared::graph::parameters parameters;
    parameters.set("color", color);

    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);
    REQUIRE(result);

    auto expected_number_of_sockets {1u};
    REQUIRE(expected_number_of_sockets == result->size());

    auto resulting_socket = (*result)[0];
    REQUIRE(resulting_socket);

    shared::graph::sockets::color color_socket(frame_width, frame_height, resulting_socket);

    auto resulting_data = color_socket.get_data();

    auto expected_data_size = frame_width * frame_height;
    REQUIRE(expected_data_size == resulting_data.size());

    for (const auto& c : resulting_data) {
        REQUIRE(color == c);
    }
}
