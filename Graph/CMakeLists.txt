#CMake Version
cmake_minimum_required(VERSION 3.20.0)

#Project name and version
project("Graph")

#C++ standard for the project
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

#Enable compiler warnings
set(COMPILER_WARNINGS ON CACHE BOOL "Add compiler warning flags")
if(${COMPILER_WARNINGS})
    if (MSVC)
        #warning level 4
        add_compile_options(/W4)
    else()
        #lots of warnings
        add_compile_options(-Wall -Wextra)
    endif()
endif()

#Enable tests
set(BUILD_TESTS ON CACHE BOOL "Build and enable tests")
if (${BUILD_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()

#Main Source Directory
add_subdirectory(src)