#include <bitset>
#include <iostream>
#include "BitArray.h"
#include "BitArrayVec.h"
#include "BitArraySmart.h"
#include <chrono>

int main()
{
    size_t n = 1000000000;

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        BitArrayVec b(n);
        for (size_t i = 0; i < b.size(); i++)
        {
            b.setBit(i, 1);
        }
        for (size_t i = 0; i < b.size(); i++)
        {
            b.getBit(i);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "BitArray: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
            << "ms"
            << '\n';
    }
}