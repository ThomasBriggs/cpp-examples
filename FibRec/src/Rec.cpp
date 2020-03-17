#include <iostream>
#include <string>

unsigned long long recFib(unsigned long long n)
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
    using namespace std;
    cout << recFib(stoi(argv[1])) << endl;
    return 0;
}
