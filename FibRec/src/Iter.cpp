#include <iostream>
#include <string>

long long iterFib(long long n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    long long prev = 1;
    long long output = 1;
    for (int i = 2; i < n; i++)
    {
        long temp = output;
        output = output + prev;
        prev = temp;
    }
    return output;
}

int main(int argc, char const *argv[])
{
    std::cout << iterFib(std::stoi(argv[1])) << std::endl;
    return 0;
}
