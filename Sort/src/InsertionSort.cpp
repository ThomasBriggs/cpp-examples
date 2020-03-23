#include <iostream>
#include "Utility.h"

void InsertionSort(int *arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            Utility::swap(arr, j, j - 1);
            j--;
        }
    }
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int amount = 100;
    if (argc == 2)
    {
        amount = stoi(argv[1]);
    }
    int arr[amount];

    Utility::fillRandom(arr, amount);
    int length = sizeof(arr) / sizeof(*arr);

    InsertionSort(arr, length);

    Utility::print(arr, amount);

    return 0;
}
