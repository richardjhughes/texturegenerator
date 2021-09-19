add_library("${NODES_SHARED_PROJECT_NAME}")

target_link_libraries("${NODES_SHARED_PROJECT_NAME}"
    PUBLIC
        glm::glm
        SAIL::sail-c++
)

add_subdirectory("graph")
add_subdirectory("graphics")
add_subdirectory("apis")
add_subdirectory("tests")
