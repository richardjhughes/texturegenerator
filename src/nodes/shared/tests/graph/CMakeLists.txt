target_sources(
    "${NODES_SHARED_TEST_PROJECT_NAME}"
    PRIVATE
        factory.cpp
        graph.cpp
        socket.cpp
        parameter.cpp
)

add_subdirectory("sockets")
