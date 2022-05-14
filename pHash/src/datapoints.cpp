#include <iostream>
#include <filesystem>
#include <vector>
#include "pHash.h"
#include <algorithm>

int main()
{
    std::filesystem::path path = "/home/thomas/Documents/cpp-examples/pHash/imgs";
    std::vector<std::filesystem::path> filepaths;
    for (auto &&i : std::filesystem::directory_iterator(path))
        filepaths.push_back(i);

    std::cout << filepaths.size() << '\n';
    std::cout << filepaths[0].filename() << '\n';

    return 0;
}
