# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thomas/Documents/cpp-examples/SFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/Documents/cpp-examples/SFML/build

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/src/test.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/test.cpp.o: ../src/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/cpp-examples/SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.dir/src/test.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/src/test.cpp.o -c /home/thomas/Documents/cpp-examples/SFML/src/test.cpp

CMakeFiles/Test.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/test.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/cpp-examples/SFML/src/test.cpp > CMakeFiles/Test.dir/src/test.cpp.i

CMakeFiles/Test.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/test.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/cpp-examples/SFML/src/test.cpp -o CMakeFiles/Test.dir/src/test.cpp.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/src/test.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

../bin/Test: CMakeFiles/Test.dir/src/test.cpp.o
../bin/Test: CMakeFiles/Test.dir/build.make
../bin/Test: /usr/local/lib/libsfml-graphics.so.2.5.1
../bin/Test: /usr/local/lib/libsfml-window.so.2.5.1
../bin/Test: /usr/local/lib/libsfml-system.so.2.5.1
../bin/Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/Documents/cpp-examples/SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: ../bin/Test

.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /home/thomas/Documents/cpp-examples/SFML/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/Documents/cpp-examples/SFML /home/thomas/Documents/cpp-examples/SFML /home/thomas/Documents/cpp-examples/SFML/build /home/thomas/Documents/cpp-examples/SFML/build /home/thomas/Documents/cpp-examples/SFML/build/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.dir/depend

