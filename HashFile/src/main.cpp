#include "hash.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <set>



int main(int argc, char const* argv[])
{

    if (argc != 2)
    {
        std::cout << "Please give a directory to scan!" << '\n';
        return 1;
    }

    std::set<sha256_t> hashes;
    std::vector<std::filesystem::path> duplicates;

    std::filesystem::path path = argv[1];
    for (auto&& i : std::filesystem::directory_iterator(path))
    {
        if (!std::filesystem::is_directory(i))
        {
            auto [_, tookPlace] = hashes.insert(hashFile(i));
            if (!tookPlace) { duplicates.push_back(i); }
        }
    }

    std::cout << duplicates.size() << '\n';
    return 0;
}
