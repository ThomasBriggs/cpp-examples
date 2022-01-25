add_executable(main main.cpp)

find_package(Curses REQUIRED)

target_link_libraries(main ${CURSES_LIBRARIES})
message(${CURSES_FOUND})

