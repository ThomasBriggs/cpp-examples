include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(BasicParse BasicParse.cpp)
add_executable(ComplexParse ComplexParse.cpp)
add_executable(SingleBracketParse SingleBracketParse.cpp)
add_executable(IndicieParse IndicieParse.cpp)
add_executable(ComplexBracketParse ComplexBracketParse.cpp)

add_executable(Test test.cpp)

target_link_libraries(BasicParse ${LIB})
target_link_libraries(ComplexParse ${LIB})
target_link_libraries(SingleBracketParse ${LIB})
target_link_libraries(IndicieParse ${LIB})
target_link_libraries(ComplexBracketParse ${LIB})

target_link_libraries(Test ${LIB})

add_test(BasicParse BasicParse)
add_test(ComplexParse ComplexParse)
add_test(SingleBracketParse SingleBracketParse)
add_test(IndicieParse IndicieParse)
add_test(ComplexBracketParse ComplexBracketParse)


