#include <iostream>
#include "Utility.h"

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int wall = start;
    for (size_t i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            Utility::swap(arr, i, wall);
            wall++;
        }
    }
    Utility::swap(arr, wall, end);
    return wall;
}

void QuickSort(int *arr, int start, int end)
{
    if (end > start)
    {
        int piv = partition(arr, start, end);
        QuickSort(arr, start, piv - 1);
        QuickSort(arr, piv + 1, end);
    }
}

void QuickSort(int *arr, int length)
{
    QuickSort(arr, 0, length - 1);
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int amount = 100;
    if (argc == 2)
    {
        amount = stoi(argv[1]);
    }
    int *arr = new int[amount];
    Utility::fillRandom(arr, amount);
    int length = sizeof(arr) / sizeof(*arr);

    QuickSort(arr, length);

    return 0;
}