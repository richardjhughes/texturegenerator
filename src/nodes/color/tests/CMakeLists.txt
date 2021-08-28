set(NODES_COLOR_TEST_PROJECT_NAME "${NODES_COLOR_PROJECT_NAME}_tests")

add_executable(
    "${NODES_COLOR_TEST_PROJECT_NAME}"
    main.cpp
    color.cpp
)

target_link_libraries(
    "${NODES_COLOR_TEST_PROJECT_NAME}"
    Catch2::Catch2
    glm::glm
    "${NODES_COLOR_PROJECT_NAME}"
)

target_include_directories(
    "${NODES_COLOR_TEST_PROJECT_NAME}"
    SYSTEM PRIVATE
    "${CATCH2_INCLUDE_DIRS}"
)

set("TEST_DATA_DIRECTORY" "${CMAKE_CURRENT_LIST_DIR}")

catch_discover_tests("${NODES_COLOR_TEST_PROJECT_NAME}")
