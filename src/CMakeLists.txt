set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.15)
project(texture_generator VERSION 1.0.0)

set(RUNNER_PROJECT_NAME "${PROJECT_NAME}_runner")
set(NODES_CREATE_PROJECT_NAME "${PROJECT_NAME}_nodes_create")

include_directories("${CMAKE_CURRENT_LIST_DIR}")

add_subdirectory("nodes")
add_subdirectory("runner")
