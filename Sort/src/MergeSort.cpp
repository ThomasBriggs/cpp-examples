#include <iostream>

void Merge(int *arr, int start, int middle, int end)
{
    int length = end - start + 1;
    int temp[length];
    int left = start;
    int right = middle + 1;
    int i = 0;

    while (left <= middle && right <= end)
    {
        if (arr[left] < arr[right])
        {
            temp[i] = arr[left];
            left++;
        }
        else
        {
            temp[i] = arr[right];
            right++;
        }
        i++;
    }

    while (left <= middle)
    {
        temp[i] = arr[left];
        left++, i++;
    }

    while (right <= end)
    {
        temp[i] = arr[right];
        right++, i++;
    }

    for (int i = 0; i < length; i++)
    {
        arr[start] = temp[i];
        start++;
    }
}

void MergeSort(int *arr, int start, int end)
{
    if (end > start)
    {
        int middle = (start + end) / 2;

        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);

        Merge(arr, start, middle, end);
    }
}

void MergeSort(int *arr, int length)
{
    MergeSort(arr, 0, length - 1);
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

    MergeSort(arr, amount);

    Utility::print(arr, amount);

    return 0;
}
