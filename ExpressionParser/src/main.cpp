#include <iostream>
#include "Expression.hpp"
#include <string>

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        Expression e = Expression::parse(argv[1]);
        std::cout << e.eval() << '\n';
    }
    return 0;
}
