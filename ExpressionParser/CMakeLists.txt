cmake_minimum_required(VERSION 3.0.0)
project(ExpressionParser VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(
    ExpressionParserLib
    src/Expression.hpp
    src/Expression.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ExpressionParserLib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
