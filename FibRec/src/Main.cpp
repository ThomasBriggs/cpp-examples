#include <iostream>
#include <string>

int recFib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return recFib(n - 1) + recFib(n - 2);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << recFib(std::stoi(argv[1])) << std::endl;
    return 0;
}
