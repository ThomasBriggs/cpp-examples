#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <iterator>
#include "BitArray.h"
#include <vector>


BitArray primeSieveSqrtBA(unsigned long long amount)
{
    amount = (amount >> 1);
    if (amount < 1)
        exit(1);

    BitArray sieveList(amount);

    size_t j = 3;

    for (size_t i = 0; i < std::floor(std::sqrt(amount)); i++)
    {
        if (!sieveList.getBit(i))
        {
            int k = j;
            while ((i + k) < amount)
            {
                sieveList.set(i + k);
                k += j;
            }
        }
        j += 2;
    }
    return sieveList;
}

std::vector<int> primesFromSeieve(const BitArray& b)
{
    std::vector<int> output;
    output.reserve(b.size() * 2 / std::log2(b.size()));
    output.emplace_back(2);
    size_t n = 3;
    for (size_t i = 0; i < b.size(); i++)
    {
        if (!b.getBit(i))
            output.push_back(n);
        n += 2;
    }
    return output;
}

void time()
{
    size_t n = 10000;
    size_t passes = 1000000;

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < passes; i++)
        {
            primeSieveSqrtBA(n);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << '\n';
    }
}

int main()
{
    auto s = primeSieveSqrtBA(100000000);
    auto v = primesFromSeieve(s);
    std::ofstream of("primesBA.txt");
    std::ostream_iterator<int> it(of, "\n");
    std::copy(v.begin(), v.end(), it);
    return 0;
}
