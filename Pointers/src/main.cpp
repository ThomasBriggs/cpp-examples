#include <iostream>
#include <string>

void *operator new(size_t size)
{
    std::cout << "New String" << std::endl;
    return malloc(size);
}

bool pal(std::string& a)
{
    char reverseStr[a.size()];
    int j = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        reverseStr[j] = a[i];
        j++;
    }
    return reverseStr == a;
}

void popLast(std::string& a)
{
    a.pop_back();
}

int main(int, char **)
{
    // std::string str = "12345hannah54321";
    // std::cout << pal(str) << std::endl;

    std::string str = "Hello";
    popLast(str);
    std::cout << str << std::endl;
}
