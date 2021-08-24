#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

std::vector<int> primeSieveSqrt(long long amount)
{
    amount = (amount / 2);
    std::vector<int> output;

    if (amount < 1)
        return output;

    output.emplace_back(2);

    std::vector<bool> sieveList(amount);

    int j = 3;

    for (int i = 0; i < std::floor(std::sqrt(amount)); i++)
    {
        if (sieveList[i] == 0)
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
        if (i == 0)
            output.emplace_back(j);
        j += 2;
    }
    return output;
}

std::vector<int> primeSieve(long long amount)
{
    amount = (amount / 2);
    std::vector<int> output;

    if (amount < 1)
        return output;

    output.emplace_back(2);

    std::vector<bool> sieveList(amount);

    int j = 3;

    for (int i = 0; i < amount; i++)
    {
        if (sieveList[i] == 0)
        {
            output.emplace_back(j);
            int k = j;
            while ((i + k) < amount)
            {
                sieveList[i + k] = 1;
                k += j;
            }
        }
        j += 2;
    }
    return output;
}

int main()
{

    long long limit = 1000000;
    std::chrono::system_clock::time_point t1, t2;
    t1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 5000; i++)
    {
        primeSieveSqrt(limit);
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << '\n';
}
