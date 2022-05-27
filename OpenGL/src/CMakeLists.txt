add_executable(main main.cpp)

find_package(glfw3 REQUIRED PATHS ~/Documents/cpp-examples/OpenGL/libs/glfw/build/lib/cmake/)
find_package(OpenGL REQUIRED)


target_link_libraries(main glfw OpenGL::GL)