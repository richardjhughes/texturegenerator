add_library("${NODES_COLOR_PROJECT_NAME}")

target_sources(
    "${NODES_COLOR_PROJECT_NAME}"
    PUBLIC
        color.h
    PRIVATE
        color.cpp
)
