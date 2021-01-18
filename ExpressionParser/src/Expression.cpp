#include "Expression.hpp"
#include <unordered_map>
#include <iostream>

Expression::Expression(std::string symbol, Expression *left, Expression *right)
    : symbol(symbol), left(left), right(right)
{
    std::cout << "Created an expression with symbol " << this->symbol << std::endl;
}

Expression::~Expression()
{
    std::cout << "Deleted expression with " << this->symbol << std::endl;
}

float Expression::eval()
{
    return Expression::evalRec(this);
}

float Expression::evalRec(Expression *e)
{
    switch (e->symbol[0])
    {
    case '+':
        return evalRec(e->left) + evalRec(e->right);
    case '-':
        return evalRec(e->left) - evalRec(e->right);
    case '*':
        return evalRec(e->left) * evalRec(e->right);
    case '/':
        return evalRec(e->left) / evalRec(e->right);
    default:
        return std::stoi(e->symbol);
    }
}

Expression Expression::parse(std::string s)
{
    //Remove whitespace
    std::string output;
    for (auto &&i : s)
    {
        if (i != ' ')
            output += i;
    }
    return parseRec(output);
}

Expression Expression::parseRec(std::string s)
{
    const std::unordered_map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 10}, {'/', 10}};
    int indexOfLowest = -1;
    int i = 0;
    for (auto &&j : s)
    {
        switch (j)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            if (indexOfLowest == -1)
                indexOfLowest = i;
            else if (precedence.at(j) <= precedence.at(s[indexOfLowest]))
                indexOfLowest = i;
            break;
        default:
            break;
        }
        i++;
    }
    if (indexOfLowest == -1)
    {
        return Expression(s, NULL, NULL);
    }
    else
    {
        return Expression(std::string(1, s[indexOfLowest]),
                          new Expression(parseRec(s.substr(0, indexOfLowest))),
                          new Expression(parseRec(s.substr(indexOfLowest + 1, s.length() - indexOfLowest - 1))));
    }
}