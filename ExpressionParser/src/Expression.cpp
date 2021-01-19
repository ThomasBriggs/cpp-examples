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
        return std::stoi(symbol);
    }
}

Expression Expression::parse(std::string s)
{
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    return parseRec(s);
}



constexpr Expression::op_precedence Expression::precedence(char ch)
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
    case '(':
    case ')':
        val = op_precedence::BRACKET;
        break;
    default:
        break;
    }
    return val;
}

Expression Expression::parseRec(const std::string &s) {
    auto lowest = std::min_element(s.begin(), s.end(), 
        [](const char &a, const char &b){
            return precedence(a) < precedence(b); 
        });
    if (precedence(*lowest) == op_precedence::NON_OP) {
        return Expression(s, nullptr, nullptr);
    } else {
        return Expression(std::string(1, *lowest),
                          std::make_unique<Expression>(parseRec(s.substr(0, lowest-s.begin()))),
                          std::make_unique<Expression>(parseRec(s.substr(lowest-s.begin() + 1)))
                          );
    }
};