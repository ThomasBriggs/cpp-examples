#include <iostream>
#include <cstdlib>
#include <ctime>

void fillRandom(int *arr, int amount)
{
    srand((unsigned)time(0));
    for (size_t i = 0; i < amount; i++)
    {
        arr[i] = rand() % (amount * 10);
    }
}

void print(int *arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

void swap(int *arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void InsertionSort(int *arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr, j, j - 1);
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
    fillRandom(arr, amount);
    int length = sizeof(arr) / sizeof(*arr);
    InsertionSort(arr, length);
    return 0;
}
