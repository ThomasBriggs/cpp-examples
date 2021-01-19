#include "Expression.hpp"

int main(int argc, char const *argv[])
{
    Expression a = Expression::parse("(2 + 3) * 2");
    if (a.eval() == 10) {
        return 0;
    } else {
        return 1;
    }
}
