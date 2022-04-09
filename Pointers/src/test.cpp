#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<std::string> v = {"Hello", "World!"};
    std::string& ref = v[0];
    std::cout << ref << '\n';

    ref = "Cheese";
    std::cout << ref << '\n';
    std::cout << v[0] << ", " << v[1] << '\n';
    return 0;
}
