set(NODES_SHARED_TEST_PROJECT_NAME "${NODES_SHARED_PROJECT_NAME}_tests")

add_executable(
    "${NODES_SHARED_TEST_PROJECT_NAME}"
    main.cpp
    util.cpp
    util.h
)

target_link_libraries(
    "${NODES_SHARED_TEST_PROJECT_NAME}"
    Catch2::Catch2
    glm::glm
    "${NODES_SHARED_PROJECT_NAME}"
)

target_include_directories(
    "${NODES_SHARED_TEST_PROJECT_NAME}"
    SYSTEM PRIVATE
    "${CATCH2_INCLUDE_DIRS}"
    "${CMAKE_CURRENT_BINARY_DIR}" # needed for `test_config.h` below
)

add_subdirectory("graph")
add_subdirectory("graphics")
add_subdirectory("apis")

file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
set(TEST_DATA_PATH \"${CMAKE_CURRENT_BINARY_DIR}/test_data\")

configure_file("test_config.h.in" "test_config.h")

catch_discover_tests("${NODES_SHARED_TEST_PROJECT_NAME}")
