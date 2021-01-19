#pragma once

#include <string>
#include <memory>

class Expression
{
public:
    float eval();
    static Expression parse(std::string s);
    enum class op_precedence
    {
        LOW,
        MED,
        HIGH,
        NON_OP,
        BRACKET
    };

private:
    Expression(std::string symbol, std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);
    static Expression parseRec(const std::string &s);
    // static Expression parseBracket(const std::string &s);
    std::string symbol;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    static constexpr op_precedence precedence(char ch);
};