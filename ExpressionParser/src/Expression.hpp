#pragma once

#include <string>
#include <memory>

class Expression
{
public:
    std::string symbol;
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

    float eval();
    static Expression parse(std::string s);

private:
    Expression(std::string symbol, Expression *left, Expression *right);
    static Expression parseRec(std::string s);
    static float evalRec(const Expression &e);
};