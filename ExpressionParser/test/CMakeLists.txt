include_directories(${CMAKE_SOURCE_DIR}/src)

# Test file
add_executable(Test test.cpp)
target_link_libraries(Test ${LIB})

# Unit Tests
add_executable(Basic Basic.cpp)
add_executable(Complex Complex.cpp)
add_executable(SingleBracket SingleBracket.cpp)
add_executable(Indicie Indicie.cpp)
add_executable(ComplexBracket ComplexBracket.cpp)
add_executable(NestedBrackets NestedBrackets.cpp)

target_link_libraries(Basic ${LIB})
target_link_libraries(Complex ${LIB})
target_link_libraries(SingleBracket ${LIB})
target_link_libraries(Indicie ${LIB})
target_link_libraries(ComplexBracket ${LIB})
target_link_libraries(NestedBrackets ${LIB})

add_test(Basic_Parse Basic)
add_test(Complex_Parse Complex)
add_test(Single_Bracket_Parse SingleBracket)
add_test(Indicie_Parse Indicie)
add_test(Complex_Bracket_Parse ComplexBracket)
add_test(Nested_Brackets_Parse NestedBrackets)


