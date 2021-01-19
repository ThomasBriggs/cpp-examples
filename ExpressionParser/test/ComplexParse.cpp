#include <iostream>
#include "Expression.hpp"

int main(int argc, char const *argv[])
{
    Expression a = Expression::parse("5 * 5 / 5 - 5");
    if (a.eval() == 0) {
        return 0;
    } else {
        return 1;
    }
}