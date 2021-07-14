#include <iostream>
#include "Link.h"
#include <vector>

int main(int argc, char const *argv[])
{
    Link<int> l1(5);
    std::cout << l1.getData() << '\n';
    return 0;
}
