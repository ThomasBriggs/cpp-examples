#include <iostream>

void swap(int *arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void print(int *arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int wall = start;
    for (size_t i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, wall);
            wall++;
        }
    }
    swap(arr, wall, end);
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

    int arr[] = {};
    int length = sizeof(arr) / sizeof(*arr);
    QuickSort(arr, length);
    return 0;
}