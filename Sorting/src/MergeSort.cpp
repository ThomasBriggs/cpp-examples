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
    int arr[] = {849, 727, 751, 903, 996, 584, 883, 214, 763, 644, 139, 792, 116, 437, 59, 389, 40, 577, 669, 68, 695, 128, 473, 863, 896, 683, 572, 477, 137, 41, 687, 986, 121, 438, 241, 117, 374, 477, 331, 490, 121, 822, 634, 238, 260, 693, 979, 652, 622, 0, 721, 317, 129, 546, 532, 25, 229, 104, 502, 719, 498, 542, 57, 619, 332, 299, 736, 707, 776, 419, 549, 249, 241, 183, 839, 853, 228, 819, 506, 850, 819, 579, 167, 300, 125, 699, 678, 706, 156, 532, 777, 654, 74, 835, 273, 407, 486, 361, 466, 614};
    int length = sizeof(arr) / sizeof(*arr);

    MergeSort(arr, 0, length - 1);

    print(arr, length);

    return 0;
}
