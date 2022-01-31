#include "file.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <random>
#include <algorithm>


std::vector<std::string> getRandomWords(const std::string f, u_short n)
{
    std::ifstream file(f);
    int number_of_lines = std::count(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>(),
        '\n'
    ) + 1;
    file.seekg(0);
    std::vector<std::string> words(n);
    std::vector<u_short> line_indices(number_of_lines);
    std::iota(begin(line_indices), end(line_indices), 0);
    std::shuffle(begin(line_indices), end(line_indices),
        std::mt19937(std::random_device().operator()()));
    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        for (int i = 0; i < n; ++i) {
            if (line_number == line_indices[i]) {
                words[i] = line;
            }
        }
        ++line_number;
    }
    return words;
}