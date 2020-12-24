#include <iostream>
#include <chrono>

void swap(int* arr, int i, int i2) {
    int temp = arr[i];
    arr[i] = arr[i2];
    arr[i2] = temp;
}

std::string printArr(int* arr, int length) {
    std::string output;
    output.push_back('[');
    for (size_t i = 0; i < length-1; i++)
    {
        output.append(std::to_string(arr[i]) + ", ");
    }
    output.append(std::to_string(arr[length-1]));
    output.push_back(']');
    return output;
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

int* bigArray(long size) {
    int* arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int amount = 100;
    if (argc == 2)
    {
        amount = stoi(argv[1]);
    }
    
    int* arr = bigArray(10000);
    std::cout <<"Hello" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(arr, 10000);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count() << std::endl;

    return 0;
}