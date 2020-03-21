#include <iostream>
#include <cstdlib>

using namespace std;

void partition(int array[], int left, int right, int pivot)
{
    while (left != right)
    {

        while (array[left] < array[pivot])
        {
            left++;
        }

        while (array[right] > array[pivot])
        {
            right--;
        }

        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
}

void quickSort(int array[], int start, int end)
{
    int length = end - start;
    int pivot = (start + end) / 2;

    partition(array, start, end, pivot);

    if (length > 2)
    {
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

void quickSort(int array[], int length)
{
    quickSort(array, 0, length - 1);
}

int main(int argc, char const *argv[])
{
    int length = 25;
    int testArray[length];
    for (int i = 0; i < length; i++)
    {
        testArray[i] = length - i;
    }

    cout << "Before" << endl;
    for (auto &&i : testArray)
    {
        cout << i << ", ";
    }
    cout << endl;

    quickSort(testArray, length);

    cout << "After" << endl;
    for (auto &&i : testArray)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
