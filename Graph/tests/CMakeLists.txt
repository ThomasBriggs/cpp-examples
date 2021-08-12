find_package(GTest)
include(GoogleTest)

link_libraries(GTest::gtest_main)
include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(VertexTest VertexTest.cpp)

gtest_discover_tests(VertexTest)