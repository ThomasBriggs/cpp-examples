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

void InsertionSort(int *arr, int length)
{

    
}

int main(int argc, char const *argv[])
{
    using namespace std;

    int arr[] = {1, 8, 95, 27, 197, 166, 180, 34, 7, 41, 88, 174, 29, 3, 161, 66, 129, 192, 54, 127};
    int length = sizeof(arr) / sizeof(*arr);

    cout << "Unsorted:" << endl;
    print(arr, length);

    cout << endl;

    InsertionSort(arr, length);

    cout << "Sorted:" << endl;
    print(arr, length);
    return 0;
}