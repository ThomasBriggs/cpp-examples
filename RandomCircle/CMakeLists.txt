#CMake Version
cmake_minimum_required(VERSION 3.16.0)

#Project name and version
project(SFMLTest VERSION 1.0.0)

#C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFMLTest main.cpp)

add_library(RandomCircle
    RandomCircle.cpp)

if (UNIX)
    set(SFML_LIBS sfml-graphics sfml-audio GL)
else()
    set(SFML_LIBS sfml-graphics sfml-audio)
endif()

target_link_libraries(SFMLTest ${SFML_LIBS})
target_link_libraries(RandomCircle ${SFML_LIBS})
target_link_libraries(SFMLTest RandomCircle)