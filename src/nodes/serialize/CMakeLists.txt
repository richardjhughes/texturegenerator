add_library("${NODES_SERIALIZE_PROJECT_NAME}")

target_sources(
    "${NODES_SERIALIZE_PROJECT_NAME}"
    PUBLIC
        serialize.h
        image_format.h
    PRIVATE
        serialize.cpp
)

target_link_libraries(
    "${NODES_SERIALIZE_PROJECT_NAME}"
    PRIVATE
        "${NODES_SHARED_PROJECT_NAME}"
        SAIL::sail-c++
)

add_subdirectory("tests")
