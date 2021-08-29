#include "catch2/catch.hpp"
#include "nodes/shared/graph/graph.h"

using namespace texturegenerator::shared::graph;

//////////
/// constructor
//////////

TEST_CASE("constructor - null factory - throws exception", "[shared/graph/graph]") {
    try {
        graph g(nullptr);
    }
    catch (const std::exception&) {
        SUCCEED("Exception thrown.");
        return;
    }

    FAIL("Exception not thrown.");
}

TEST_CASE("constructor - non-null factory - does not throw exception", "[shared/graph/graph]") {
    try {
        graph g(std::make_unique<factory>());
    }
    catch (const std::exception&) {
        FAIL("Exception thrown.");
        return;
    }

    SUCCEED("Exception not thrown.");
}
