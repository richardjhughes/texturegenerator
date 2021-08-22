add_library("${NODES_SHARED_PROJECT_NAME}")

target_sources(
    "${NODES_SHARED_PROJECT_NAME}"
    PUBLIC
        color.h
    PRIVATE
        color.cpp
)
