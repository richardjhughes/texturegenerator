add_executable("${RUNNER_PROJECT_NAME}")

target_link_libraries(
    "${RUNNER_PROJECT_NAME}"
    PRIVATE
        "${NODES_COLOR_PROJECT_NAME}"
		"${NODES_SERIALIZE_PROJECT_NAME}"
)

target_sources(
    "${RUNNER_PROJECT_NAME}"
	PUBLIC
		runner.h
    PRIVATE
        main.cpp
		runner.cpp
)

install(
	TARGETS
		"${RUNNER_PROJECT_NAME}"
	DESTINATION
		"${INSTALL_DIRECTORY}"
)

add_subdirectory("tests")
