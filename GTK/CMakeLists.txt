cmake_minimum_required(VERSION 3.19)
# Set the name and the supported language of the project
PROJECT(hello-world C)
# Set the minimum version of cmake required to build this project

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtkmm-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

add_executable(hello main.cpp)
TARGET_LINK_LIBRARIES(hello ${GTK_LIBRARIES})