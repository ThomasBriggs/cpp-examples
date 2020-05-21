cmake_minimum_required(VERSION 3.0.0)
project(TestApplicatoin)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

set(SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/src)

link_libraries(sfml-graphics)

add_executable(Application src/main.cpp src/Ball.cpp)
add_executable(Test src/test.cpp)

