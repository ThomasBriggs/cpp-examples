#include <iostream>

void swap(int *arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int partition(int *arr, int low, int high)
{
    int wall = low + 1;
    int pivot = arr[low];
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, wall);
            wall++;
        }
    }
    swap(arr, low, wall - 1);
    return wall - 1;
}

void sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int piv = partition(arr, low, high);
        sort(arr, low, piv - 1);
        sort(arr, piv + 1, high);
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

int main(int argc, char const *argv[])
{
    using namespace std;

    int arr[] = {576, 248, 542, 55, 641, 216, 719, 848, 979, 811, 203, 756, 416, 423, 564, 502, 512, 227, 102, 743, 241, 490, 639, 313, 84, 627, 814, 60, 438, 496, 172, 366, 96, 66, 773, 737, 634, 492, 585, 966, 303, 789, 722, 72, 564, 286, 574, 428, 865, 677, 171, 106, 519, 810, 771, 603, 790, 586, 15, 228, 82, 188, 946, 530, 606, 719, 267, 241, 211, 205, 207, 867, 346, 281, 939, 910, 567, 865, 690, 784, 542, 213, 890, 414, 376, 661, 17, 166, 599, 33, 746, 33, 573, 692, 563, 531, 411, 831, 772, 974};
    int length = sizeof(arr) / sizeof(*arr);

    cout << "Unsorted:" << endl;
    print(arr, length);

    cout << endl;

    sort(arr, 0, length - 1);

    cout << "Sorted:" << endl;
    print(arr, length);
    return 0;
}
