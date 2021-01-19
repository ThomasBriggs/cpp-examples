#include <iostream>
#include "Expression.hpp"

int main(int argc, char const *argv[])
{
    Expression a = Expression::parse("2 + 5 * 10");
    std::cout << a.eval() << '\n';

    return 0;
}
