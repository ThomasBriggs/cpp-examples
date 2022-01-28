add_executable(test test.cpp)



find_package(Curses REQUIRED)
link_libraries(${CURSES_LIBRARIES})
add_library(menu Menu.cpp MenuItem.cpp)
link_libraries(menu)
add_executable(main main.cpp)
