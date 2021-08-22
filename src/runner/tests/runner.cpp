#include "catch2/catch.hpp"
#include "runner/runner.h"

using namespace texturegenerator;

TEST_CASE("Sets program arguments", "[runner]") {
    std::vector<std::string> args { "arg1", "arg2" };

    runner r(args);

    REQUIRE(r.args() == args);
}
