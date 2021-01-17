#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Expression
{
public:
    std::string Symbol;
    Expression *left;
    Expression *right;

    Expression(std::string Symbol, Expression *left, Expression *right)
    {
        this->Symbol = Symbol;
        this->left = left;
        this->right = right;
    }

    static float eval(Expression *e)
    {
        switch (e->Symbol[0])
        {
        case '+':
            return eval(e->left) + eval(e->right);
        case '-':
            return eval(e->left) - eval(e->right);
        case '*':
            return eval(e->left) * eval(e->right);
        case '/':
            return eval(e->left) / eval(e->right);
        default:
            return std::stoi(e->Symbol);
        }
    }

    static Expression parse(std::string s) {
        //Remove whitespace
        std::string output;
        for (auto &&i : s)
        {
            if (i != ' ')
                output += i;
        }
        return parseRec (output);
        
    }

    static Expression parseRec(std::string s) {
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
                if (indexOfLowest == -1) indexOfLowest = j;
                else if (precedence.at(j) < precedence.at(indexOfLowest))
                    indexOfLowest = j;
                break;
            default:
                break;
            }
            i++;
        }
        if (indexOfLowest == -1) {
            return Expression(s, NULL, NULL);
        } else {
            return Expression(std::string(1, s[indexOfLowest]), 
                &parseRec(s.substr(0, indexOfLowest-1)), 
                &parseRec(s.substr(indexOfLowest + 1, s.length() - indexOfLowest)));
        }
    }
        
};

int main(int argc, char const *argv[])
{
    Expression a_left = Expression("5", NULL, NULL);
    Expression a_right = Expression("2", NULL, NULL);
    Expression a = Expression("*", &a_left, &a_right);
    Expression b_left = Expression("3", NULL, NULL);
    Expression b = Expression("+", &a, &b_left);
    std::cout << Expression::eval(&b) << std::endl;
    return 0;
}
