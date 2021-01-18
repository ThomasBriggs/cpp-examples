include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(Test1 BasicParse1.cpp)
add_executable(Test2 BasicParse2.cpp)

target_link_libraries(Test1 ExpressionParserLib)
target_link_libraries(Test2 ExpressionParserLib)

add_test(BaiscParse Test1)
add_test(ComplexParse Test2)


