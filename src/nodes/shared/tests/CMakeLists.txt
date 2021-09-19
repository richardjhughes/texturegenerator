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
)

target_compile_definitions(
    "${NODES_SHARED_TEST_PROJECT_NAME}"
    PRIVATE
        TEST_DATA_DIRECTORY=${CMAKE_CURRENT_LIST_DIR}/test_data
)

add_subdirectory("graph")
add_subdirectory("graphics")
add_subdirectory("apis")

catch_discover_tests("${NODES_SHARED_TEST_PROJECT_NAME}")
