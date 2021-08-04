#include <iostream>
#include <string>

uint64_t fib(int n)
{
    int start = 0;
    int prev = 1;
    while (n > 0)
    {
        int temp = start;
        start = start + prev;
        prev = temp;
        n--;
    }
    return start;
}

uint64_t fibRec(int n)
{
    return n <= 1 ? n : fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
    std::cout << fibRec(10000) << '\n';
    std::cout << fib(10000) << '\n';
    return 0;
}
