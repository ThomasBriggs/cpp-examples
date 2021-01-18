#include <iostream>
#include "Expression.hpp"

int main(int argc, char const *argv[])
{
    //Parsed expression tree
    Expression e = Expression::parse("+5");
    std::cout << e.eval() << std::endl;
    return 0;
}
