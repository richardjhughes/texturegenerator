#include "catch2/catch.hpp"
#include "nodes/shared/tests/util.h"
#include "nodes/shared/apis/image/image.h"

using namespace texturegenerator::shared;
using namespace texturegenerator::shared::apis::image;

//////////
/// serialize_image
//////////

TEST_CASE("serialize_image - empty data - returns error", "[shared/apis/image]") {
    auto width { 16u };
    auto height { 16u };

    std::vector<graphics::color> data;

    auto result = serialize_image(data, width, height);

    REQUIRE_FALSE(result);
}

TEST_CASE("serialize_image - data incorrect size - returns error", "[shared/apis/image]") {
    auto width { 16u };
    auto height { 16u };

    std::vector<graphics::color> data {
        graphics::colors::black,
        graphics::colors::black,
        graphics::colors::black,
        graphics::colors::black,
    };

    auto result = serialize_image(data, width, height);

    REQUIRE_FALSE(result);
}

TEST_CASE("serialize_image - valid data - does not return error", "[shared/apis/image]") {
    auto width { 16u };
    auto height { 16u };

    std::vector<graphics::color> data;

    for (auto i {0u}; i < width * height; ++i) {
        data.push_back(graphics::colors::black);
    }

    auto result = serialize_image(data, width, height);

    REQUIRE(result);
}

TEST_CASE("serialize_image - valid data - returns serialized data", "[shared/apis/image]") {
    auto width { 16u };
    auto height { 16u };

    std::vector<graphics::color> data;

    for (auto i {0u}; i < width * height; ++i) {
        data.push_back(graphics::colors::red);
    }

    auto result = serialize_image(data, width, height);

    auto expected = get_data_from_file("16x16_red.png");

    REQUIRE(result);
    REQUIRE(expected.size() == result->size());
    for (auto i {0u}; i < expected.size(); ++i) {
        REQUIRE(static_cast<std::byte>(expected[i]) == (*result)[i]);
    }
}
