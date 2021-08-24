#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <iterator>

std::vector<unsigned long long> primeSieveSqrt(unsigned long long amount)
{
    amount = (amount / 2);
    std::vector<unsigned long long> output;

    if (amount < 1)
        return output;

    output.emplace_back(2);

    std::vector<bool> sieveList(amount);

    size_t j = 3;

    for (size_t i = 0; i < std::floor(std::sqrt(amount)); i++)
    {
        if (!sieveList[i])
        {
            int k = j;
            while ((i + k) < amount)
            {
                sieveList[i + k] = 1;
                k += j;
            }
        }
        j += 2;
    }

    j = 3;
    for (auto&& i : sieveList)
    {
        if (!i)
            output.emplace_back(j);
        j += 2;
    }
    return output;
}


int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 5000; i++)
    {
        auto v = primeSieveSqrt(1000000);
    }
    
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << '\n';

    // std::ofstream of("primes.txt");
    // std::ostream_iterator<unsigned long long> oit(of, "\n");
    // std::copy(v.begin(), v.end(), oit);
}
