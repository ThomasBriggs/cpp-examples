#include <iostream>
#include "Expression.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    std::string output;
    for (size_t i = 1; i < argc; i++)
    {
        output.append(argv[i]);
    }
    cout << output << '\n';
}
