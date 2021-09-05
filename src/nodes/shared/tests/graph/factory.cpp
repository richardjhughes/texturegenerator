#include "catch2/catch.hpp"
#include "nodes/shared/graph/factory.h"

using namespace texturegenerator::shared::graph;

class test_node : public node {
    [[nodiscard]]
    std::optional<socket_list> run(glm::vec4,
                                   uint32_t, uint32_t,
                                   const parameters&,
                                   const socket_list&) noexcept override {
        return {};
    }

    [[nodiscard]]
    node_types get_node_type() noexcept override {
        // use a random type
        return node_types::color;
    }
};

//////////
/// register_node
//////////

TEST_CASE("register_node - valid type - does not return error", "[shared/graph/factory]") {
    auto type = node_types::color;

    factory f;

    auto result = f.register_node(type, [](){ return std::make_shared<test_node>(); });
    REQUIRE(result);
}

TEST_CASE("register_node - valid type - registers node", "[shared/graph/factory]") {
    auto type = node_types::color;

    factory f;

    f.register_node(type, [](){ return std::make_shared<test_node>(); });

    auto result = f.create(type);
    REQUIRE(result);

    auto node = *result;
    REQUIRE(node->get_node_type() == type);
}

TEST_CASE("register_node - type already registered - returns error", "[shared/graph/factory]") {
    auto type = node_types::color;

    factory f;

    auto result = f.register_node(type, [](){ return std::make_shared<test_node>(); });
    REQUIRE(result);

    result = f.register_node(type, [](){ return std::make_shared<test_node>(); });
    REQUIRE_FALSE(result);
}

//////////
/// create
//////////

TEST_CASE("create - registered type - creates node", "[shared/graph/factory]") {
    auto type = node_types::color;

    factory f;

    f.register_node(type, [](){ return std::make_unique<test_node>(); });

    auto result = f.create(type);
    REQUIRE(result);

    auto node = *result;
    REQUIRE(node->get_node_type() == type);
}

TEST_CASE("create - unregistered type - returns error", "[shared/graph/factory]") {
    auto invalid_type = (node_types)99999;

    factory f;

    auto node = f.create(invalid_type);

    REQUIRE_FALSE(node);
}
