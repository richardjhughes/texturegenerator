add_library("${NODES_CREATE_PROJECT_NAME}")

target_sources(
    "${NODES_CREATE_PROJECT_NAME}"
    PUBLIC
        create.h
    PRIVATE
        create.cpp
)
