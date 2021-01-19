#include <iostream>
#include "Expression.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

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

    int i = 10;
    int* i_ptr = &i;
    cout << *i_ptr << '\n';
    return 0;
}
