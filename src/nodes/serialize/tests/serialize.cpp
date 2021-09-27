#include "catch2/catch.hpp"
#include "util.h"
#include "nodes/serialize/serialize.h"
#include "nodes/serialize/image_format.h"
#include "nodes/shared/graph/sockets/binary_stream.h"
#include "nodes/shared/graph/sockets/color_channel.h"

using namespace texturegenerator;
using namespace texturegenerator::shared::graphics;
using namespace texturegenerator::shared::graph;
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

TEST_CASE("run - no image type parameter - returns error", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };

    shared::graph::parameters parameters;
    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE_FALSE(result);
}

TEST_CASE("run - invalid number of input sockets - returns error", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto image_format { image_formats::PNG };

    shared::graph::parameters parameters;
    parameters.set("image_format", static_cast<uint32_t>(image_format));

    // missing alpha
    sockets::color_channel socket_red;
    sockets::color_channel socket_green;
    sockets::color_channel socket_blue;

    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;
    sockets_in.push_back(socket_red.get_socket());
    sockets_in.push_back(socket_green.get_socket());
    sockets_in.push_back(socket_blue.get_socket());

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE_FALSE(result);
}

TEST_CASE("run - input socket data not equal to frame size - returns error", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto image_format { image_formats::PNG };

    shared::graph::parameters parameters;
    parameters.set("image_format", static_cast<uint32_t>(image_format));

    auto frame_size = frame_width * frame_height;

    std::vector<uint8_t> data;
    data.resize(frame_size);

    std::vector<uint8_t> invalid_data;
    data.resize(1);

    for (auto i {0u}; i < 4; ++i)
    {
        sockets::color_channel socket_red;
        sockets::color_channel socket_green;
        sockets::color_channel socket_blue;
        sockets::color_channel socket_alpha;

        socket_red.set_data(i == 0 ? invalid_data : data);
        socket_green.set_data(i == 1 ? invalid_data : data);
        socket_blue.set_data(i == 2 ? invalid_data : data);
        socket_alpha.set_data(i == 3 ? invalid_data : data);

        std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;
        sockets_in.push_back(socket_red.get_socket());
        sockets_in.push_back(socket_green.get_socket());
        sockets_in.push_back(socket_blue.get_socket());
        sockets_in.push_back(socket_alpha.get_socket());

        auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

        REQUIRE_FALSE(result);
    }
}

TEST_CASE("run - valid parameters - does not return error", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto image_format { image_formats::PNG };

    shared::graph::parameters parameters;
    parameters.set("image_format", static_cast<uint32_t>(image_format));

    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE(result);
}

TEST_CASE("run - valid parameters, no input sockets - serializes default color", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto image_format { image_formats::PNG };

    shared::graph::parameters parameters;
    parameters.set("image_format", static_cast<uint32_t>(image_format));

    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE(result);
    REQUIRE(!result->empty());

    auto sockets = *result;
    sockets::binary_stream s(sockets[0]);

    auto data = s.get_data();

    auto expected = get_data_from_file("32x64_default_color.png");

    REQUIRE(expected.size() == data.size());
    for (auto i {0u}; i < expected.size(); ++i) {
        REQUIRE(static_cast<std::byte>(expected[i]) == data[i]);
    }
}

TEST_CASE("run - valid input sockets - serializes color", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto image_format { image_formats::PNG };

    shared::graph::parameters parameters;
    parameters.set("image_format", static_cast<uint32_t>(image_format));

    std::vector<std::pair<color, std::string>> colors_to_test {
        { colors::red, "red", },
        { colors::green, "green", },
        { colors::blue, "blue", },
        { colors::white, "white", },
        { colors::black, "black", },
    };

    auto frame_size = frame_width * frame_height;

    for (const auto& [color, color_name] : colors_to_test) {
        std::vector<uint8_t> red_data;
        std::vector<uint8_t> green_data;
        std::vector<uint8_t> blue_data;
        std::vector<uint8_t> alpha_data;

        red_data.resize(frame_size);
        green_data.resize(frame_size);
        blue_data.resize(frame_size);
        alpha_data.resize(frame_size);

        std::fill(red_data.begin(), red_data.end(), color.r);
        std::fill(green_data.begin(), green_data.end(), color.g);
        std::fill(blue_data.begin(), blue_data.end(), color.b);
        std::fill(alpha_data.begin(), alpha_data.end(), color.a);

        sockets::color_channel socket_red;
        sockets::color_channel socket_green;
        sockets::color_channel socket_blue;
        sockets::color_channel socket_alpha;

        socket_red.set_data(red_data);
        socket_green.set_data(green_data);
        socket_blue.set_data(blue_data);
        socket_alpha.set_data(alpha_data);

        std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;
        sockets_in.push_back(socket_red.get_socket());
        sockets_in.push_back(socket_green.get_socket());
        sockets_in.push_back(socket_blue.get_socket());
        sockets_in.push_back(socket_alpha.get_socket());

        auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

        REQUIRE(result);
        REQUIRE(!result->empty());

        auto sockets = *result;
        sockets::binary_stream s(sockets[0]);

        auto data = s.get_data();

        auto color_file_name { "32x64_" + color_name + ".png" };
        auto expected = get_data_from_file(color_file_name);

        INFO(color_name);
        REQUIRE(expected.size() == data.size());
        for (auto i {0u}; i < expected.size(); ++i) {
            REQUIRE(static_cast<std::byte>(expected[i]) == data[i]);
        }
    }
}
