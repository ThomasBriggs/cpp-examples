cmake_minimum_required(VERSION 3.16.3)
project(MyProject VERSION 1.0.0)

add_library(
    say-hello 
    hello.hpp
    hello.cpp
)

add_executable(cmake-test main.cpp)

target_link_libraries(cmake-test PRIVATE say-hello)
