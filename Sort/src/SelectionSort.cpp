#include <iostream>

void SelectionSort(int *arr, int length)
{
    int smallest;
    for (size_t i = 0; i < length; i++)
    {
        smallest = i;
        for (size_t j = i; j < length; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        Utility::swap(arr, i, smallest);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 53, 83, 64, 21, 42, 20, 86, 81, 3};
    int length = sizeof(arr) / sizeof(*arr);

    SelectionSort(arr, length);
    Utility::print(arr, length);

    return 0;
}
