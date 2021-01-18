#pragma once

#include <string>

class Expression
{
public:
    std::string symbol;
    Expression *left;
    Expression *right;

    Expression(std::string symbol, Expression *left, Expression *right);
    ~Expression();
    float eval();
    static Expression parse(std::string s);

private:
    static Expression parseRec(std::string s);
    static float evalRec(Expression *e);
};