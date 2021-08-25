#include <cstring>
#include <bitset>
#include <iostream>
#include "BitArray.h"

int main()
{
    BitArray b(100);
    b.setBit(33, 1);
    b.setBit(66, 1);
    b.setBit(99, 1);
    for (size_t i = 0; i < b.size(); i++)
    {
        std::cout << i << " : " << b.getBit(i) << '\n';
    }
    std::cout << '\n';
}