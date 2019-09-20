
#include <iostream>
#include <vector>
#include "prime.h"
#include "fibanacci.h"
#include "sort.h"

using namespace fib;
using namespace std;
using namespace prime;


int main()
{
    vector<int> arr = primeGenerator(100);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;

    cout << fibGen(5) << endl;
    cout << fibGen(10) << endl;

    int nums[] = {7, 81, 80, 75, 71, 40, 12, 45, 72, 82, 84, 75, 17, 90, 66, 89, 93, 96, 53, 26};
    sort::bubbleSort(nums, sizeof(nums)/sizeof(nums[0]));
    for (size_t i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
    {
        cout << nums[i] << ", ";
    }
    cout << endl;
}
