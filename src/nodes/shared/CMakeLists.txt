add_library("${NODES_SHARED_PROJECT_NAME}")

target_link_libraries("${NODES_SHARED_PROJECT_NAME}" glm::glm)

add_subdirectory("graph")
add_subdirectory("graphics")
