#include <cstring>
#include <bitset>
#include <iostream>
#include "BitArray.h"

int main()
{
    BitArray b(32);
    b.setBit(30, 1);
    std::cout << b.getBit(29) << '\n';
}