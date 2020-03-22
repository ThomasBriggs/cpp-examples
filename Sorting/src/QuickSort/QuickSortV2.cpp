#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int leftwall = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            leftwall++;

            int temp = arr[i];
            arr[i] = arr[leftwall];
            arr[leftwall] = temp;
        }
    }

    int temp = arr[leftwall + 1];
    arr[leftwall + 1] = arr[high];
    arr[high] = temp;

    return leftwall + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
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

    quickSort(testArray, 0, length - 1);

    cout << "After" << endl;
    for (auto &&i : testArray)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
