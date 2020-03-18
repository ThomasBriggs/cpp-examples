#include <iostream>
#include <cstdlib>

using namespace std;

void quickSort(int array[], int start, int end)
{

    if (start < end)
    {

        int left = start;
        int right = end;
        int length = start + end;
        int pivot = length / 2;

        while (left != right)
        {

            left = start;
            right = end;

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
    int length = 50;
    int testArray[length];
    for (int i = 0; i < length; i++)
    {
        testArray[i] = rand() % 1000;
    }

    quickSort(testArray, length);
    for (auto &&i : testArray)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
