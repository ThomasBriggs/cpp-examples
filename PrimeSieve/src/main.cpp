#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <iterator>
#include "BitArray.h"
#include <vector>


BitArray primeSieve(unsigned long long amount)
{
    if (amount < 2)
        return BitArray(0);

    amount = (amount >> 1);
    BitArray sieveList(amount);
    size_t j = 3;

    for (size_t i = 0; i < std::floor(std::sqrt(amount)); i++)
    {
        if (!sieveList.get(i))
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

std::vector<int> primesFromSieve(const BitArray& b)
{
    std::vector<int> output;
    output.reserve(b.size() * 2 / std::log2(b.size()));
    output.emplace_back(2);
    size_t n = 3;
    for (size_t i = 0; i < b.size(); i++)
    {
        if (!b.get(i))
            output.push_back(n);
        n += 2;
    }
    return output;
}

void time()
{
    size_t n = 1000000;
    size_t passes = 8000;

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < passes; i++)
        {
            primeSieve(n);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << '\n';
    }

    {
        auto v = primeSieve(n);
        auto t1 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < passes; i++)
        {
            primesFromSieve(v);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << '\n';
    }
}

void writeToFile(int n, const char* filename)
{
    auto s = primeSieve(n);
    auto v = primesFromSieve(s);
    std::ofstream of(filename);
    std::ostream_iterator<int> it(of, "\n");
    std::copy(v.begin(), v.end(), it);
}

int main()
{
    // time();
    writeToFile(1000000000, "primes.txt");
}
