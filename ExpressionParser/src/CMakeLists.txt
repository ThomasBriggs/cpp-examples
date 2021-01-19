add_library(
    ExpressionParserLib
    Expression.hpp
    Expression.cpp
)

add_executable(Expression main.cpp)
set_target_properties(Expression PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries(Expression ${LIBS})