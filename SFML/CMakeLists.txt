cmake_minimum_required(VERSION 3.0.0)
project(TestApplicatoin)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_executable(Application src/main.cpp)
add_executable(Test src/test.cpp)
target_link_libraries(Application sfml-graphics)
target_link_libraries(Test sfml-graphics)

