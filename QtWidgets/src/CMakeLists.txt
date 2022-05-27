find_package(Qt6Widgets REQUIRED PATHS /usr/loca/Qt-6.3.1/lib/cmake)


add_executable(main main.cpp)
target_link_libraries(main Qt6::Widgets)