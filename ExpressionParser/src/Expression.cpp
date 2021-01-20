#include "Expression.hpp"
#include <algorithm>
#include <cmath>

Expression::Expression(std::string symbol, std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right)
    : symbol(symbol), left(std::move(left)), right(std::move(right)) {}

float Expression::eval()
{
    switch (symbol[0])
    {
    case '+':
        return left->eval() + right->eval();
    case '-':
        return left->eval() - right->eval();
    case '*':
        return left->eval() * right->eval();
    case '/':
        return left->eval() / right->eval();
    case '^':
        return std::pow(left->eval(), right->eval());
    default:
        return std::stof(symbol);
    }
}

Expression Expression::parse(std::string s)
{
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    Expression r = parseRec(s);
    return r;
}

constexpr Expression::op_precedence Expression::precedence(const char &ch)
{
    op_precedence val = op_precedence::NON_OP;
    switch (ch)
    {
    case '+':
    case '-':
        val = op_precedence::LOW;
        break;
    case '*':
    case '/':
        val = op_precedence::MED;
        break;
    case '^':
        val = op_precedence::HIGH;
        break;
    default:
        break;
    }
    return val;
}

Expression Expression::parseRec(const std::string &s)
{
    if (s.empty()) {
        return Expression("0", nullptr, nullptr);
    }

    std::string::const_iterator lowestOp = s.begin();
    int openBrackets = 0;
    for (std::string::const_iterator i = s.begin(); i != s.end(); i++)
    {
        switch (*i)
        {
        case '(':
            openBrackets++;
            break;
        case ')':
            openBrackets--;
            break;
        }
        if (openBrackets == 0)
            if (precedence(*i) < precedence(*lowestOp))
                lowestOp = i;
    }
    if (*lowestOp == '(')
    {
        return parseRec(s.substr(1, s.length() - 2));
    }
    else if (precedence(*lowestOp) == op_precedence::NON_OP)
    {
        return Expression(s, nullptr, nullptr);
    }
    else
    {
        return Expression(std::string(1, *lowestOp),
                          std::make_unique<Expression>(parseRec(s.substr(0, lowestOp - s.begin()))),
                          std::make_unique<Expression>(parseRec(s.substr(lowestOp - s.begin() + 1))));
    }
};