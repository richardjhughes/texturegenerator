add_library("${NODES_SERIALIZE_PROJECT_NAME}")

target_sources(
    "${NODES_SERIALIZE_PROJECT_NAME}"
    PUBLIC
        serialize.h
    PRIVATE
        serialize.cpp
)
