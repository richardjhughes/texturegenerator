add_library("${NODES_COLOR_PROJECT_NAME}")

target_sources(
    "${NODES_COLOR_PROJECT_NAME}"
    PUBLIC
        color.h
    PRIVATE
        color.cpp
)

target_link_libraries(
    "${NODES_COLOR_PROJECT_NAME}"
    PRIVATE
        "${NODES_SHARED_PROJECT_NAME}"
)

add_subdirectory("tests")
