set(NODES_SERIALIZE_TEST_PROJECT_NAME "${NODES_SERIALIZE_PROJECT_NAME}_tests")

add_executable(
    "${NODES_SERIALIZE_TEST_PROJECT_NAME}"
    main.cpp
    serialize.cpp
    util.h
    util.cpp
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
        "${CMAKE_CURRENT_BINARY_DIR}" # needed for `test_config.h` below
)

file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
set(TEST_DATA_PATH \"${CMAKE_CURRENT_BINARY_DIR}/test_data\")

configure_file("test_config.h.in" "test_config.h")

catch_discover_tests("${NODES_SERIALIZE_TEST_PROJECT_NAME}")
