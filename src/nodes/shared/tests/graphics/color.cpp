#include "catch2/catch.hpp"
#include "nodes/shared/graphics/color.h"

using namespace texturegenerator::shared::graphics;

//////////
/// operator ==
//////////

TEST_CASE("operator == - are equal - returns true", "[shared/graphics/color]") {
    color color_1 {
      1, 2, 3, 4,
    };

    color color_2 {
        1, 2, 3, 4,
    };

    REQUIRE(color_1 == color_2);
}

TEST_CASE("operator == - not equal - returns false", "[shared/graphics/color]") {
    color color_1 {
    1, 2, 3, 4,
    };

    color color_2 {
        5, 6, 7, 8,
    };

    REQUIRE_FALSE(color_1 == color_2);
}

//////////
/// operator !=
//////////

TEST_CASE("operator != - not equal - returns true", "[shared/graphics/color]") {
    color color_1 {
    1, 2, 3, 4,
    };

    color color_2 {
    5, 6, 7, 8,
    };

    REQUIRE(color_1 != color_2);
}

TEST_CASE("operator != - are equal - returns false", "[shared/graphics/color]") {
    color color_1 {
        1, 2, 3, 4,
    };

    color color_2 {
        1, 2, 3, 4,
    };

    REQUIRE_FALSE(color_1 != color_2);
}
