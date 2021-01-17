#include <iostream>

void BubbleSort(int *arr, int length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Utility::swap(arr, j, j + 1);
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

    Utility::fillRandom(arr, amount);

    BubbleSort(arr, amount);

    Utility::print(arr, amount);

    return 0;
}