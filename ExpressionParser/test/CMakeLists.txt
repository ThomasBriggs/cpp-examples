include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(Test1 BasicParse1.cpp)
add_executable(Test2 BasicParse2.cpp)
add_executable(Test3 BracketParse.cpp)
add_executable(Test4 IndicieParse.cpp)

add_executable(Test test.cpp)

target_link_libraries(Test1 ${LIB})
target_link_libraries(Test2 ${LIB})
target_link_libraries(Test3 ${LIB})
target_link_libraries(Test4 ${LIB})

target_link_libraries(Test ${LIB})


add_test(BaiscParse Test1)
add_test(ComplexParse Test2)
add_test(BrakcetParse Test3)
add_test(IndicieParse Test4)


