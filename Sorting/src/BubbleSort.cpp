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

void BubbleSort(int *arr, int length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int amount;

    if (argc > 1)
    {
        amount = std::stoi(argv[1]);
    }
    else
    {
        amount = 100;
    }

    int *arr = new int[amount];

    fillRandom(arr, amount);

    BubbleSort(arr, amount);

    print(arr, amount);

    return 0;
}