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

    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    auto test = min_element(a.begin(), a.end(),
        [](int a, int b){
            return a < b;
        });

    cout << *(a.end()-1) << '\n';
    cout << *test << '\n';

    unordered_map<string, int> map = {
        {"Hello", 1},
        {"World", 2}
    };

    for (unordered_map<string, int>::iterator i = map.begin(); i != map.end(); i++)
    {
        cout << i->first << ", " << i->second << '\n';
    }
   
}
