find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
add_executable(main main.cpp)