#CMake Version
cmake_minimum_required(VERSION 3.20.0)

#Project name and version
project(TemplatedLinkedList VERSION 1.0.0)

#C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)