set(NODES_SERIALIZE_TEST_PROJECT_NAME "${NODES_SERIALIZE_PROJECT_NAME}_tests")

add_executable(
    "${NODES_SERIALIZE_TEST_PROJECT_NAME}"
    main.cpp
    serialize.cpp
)

target_link_libraries(
    "${NODES_SERIALIZE_TEST_PROJECT_NAME}"
    PRIVATE
        Catch2::Catch2
        glm::glm
        "${NODES_SHARED_PROJECT_NAME}"
        "${NODES_SERIALIZE_PROJECT_NAME}"
)

target_include_directories(
    "${NODES_SERIALIZE_TEST_PROJECT_NAME}"
    SYSTEM PRIVATE
        "${CATCH2_INCLUDE_DIRS}"
)

set("TEST_DATA_DIRECTORY" "${CMAKE_CURRENT_LIST_DIR}")

catch_discover_tests("${NODES_SERIALIZE_TEST_PROJECT_NAME}")
