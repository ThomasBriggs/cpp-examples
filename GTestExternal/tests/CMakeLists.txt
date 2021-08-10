enable_testing()
include(GoogleTest)

add_executable(
    test
    test.cc
)

target_link_libraries(test googletest)
gtest_discover_tests(test)

