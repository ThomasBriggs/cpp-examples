#include "pHash.h"
#include <array>
#include <bitset>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <random>

class hamHash {
private:
    std::array<int, 10> randomIndexes;

public:
    hamHash()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<uint64_t> distrib(0, 64);
        for (auto& i : randomIndexes)
            i = distrib(rd);
    }

    bitset<10> hash(uint64_t input)
    {
        std::bitset<10> hashBits;
        
        return hashBits;
    }
};

int main()
{
    std::filesystem::path path = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro_original.jpg";
    std::filesystem::path path1 = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro_mod.jpg";
    uint64_t hash = 0;
    uint64_t hash1;
    ph_dct_imagehash(path.c_str(), hash);
    ph_dct_imagehash(path1.c_str(), hash1);

    hamHash hasher{};

    std::cout << hasher.hash(hash) << '\n';
    std::cout << hasher.hash(hash1) << '\n';
    return 0;
}