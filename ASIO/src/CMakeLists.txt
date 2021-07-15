add_library(asio INTERFACE)
target_include_directories(asio INTERFACE /usr/include/)
target_link_libraries(asio INTERFACE pthread)

add_executable(main main.cpp)
target_link_libraries(main asio)