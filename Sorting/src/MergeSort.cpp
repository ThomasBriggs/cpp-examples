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

void Merge(int *arr, int start, int middle, int end)
{
    int length = start + end + 1;
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

    if (left > middle)
    {
        for (i; i < length; i++)
        {
            temp[i] = arr[right];
            right++;
        }
    }
    else
    {
        for (i; i < length; i++)
        {
            temp[i] = arr[left];
            left++;
        }
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

int main(int argc, char const *argv[])
{
    int arr[] = {8, 6, 4, 1};
    int length = sizeof(arr) / sizeof(*arr);

    Merge(arr, 2, 3, 2);
    print(arr, length);

    return 0;
}
