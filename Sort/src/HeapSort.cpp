#include <iostream>
#include <chrono>

void swap(int* arr, int i, int i2) {
    int temp = arr[i];
    arr[i] = arr[i2];
    arr[i2] = temp;
}

std::string printArr(int* arr, int length) {
    std::string output;
    output.push_back('[');
    for (size_t i = 0; i < length-1; i++)
    {
        output.append(std::to_string(arr[i]) + ", ");
    }
    output.append(std::to_string(arr[length-1]));
    output.push_back(']');
    return output;
}

void maxHeap(int* arr, int length) {
    int mid = length / 2;
    for (int i = mid; i >= 0; i--)
    {
        bool correctPos = false;
        while (!correctPos) {
            int index = i;
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            bool hasLeft = left < length;
            bool hasRight = right < length;
            if (hasLeft) {
                if (arr[index] < arr[left]) {
                    int swapIndex = left;
                    if (hasRight) {
                        if (arr[right] > arr[left]) {
                            swapIndex = right;
                        }
                    }
                    swap(arr, index, swapIndex);
                    index = swapIndex;
                } else {
                    if (hasRight) {
                        if (arr[index] < arr[right]) {
                            swap(arr, index, right);
                            index = right;
                        }
                    }
                    correctPos = true;
                }
            } else {
                    correctPos = true;
            }
        }
    }
}

void mergeSort(int* arr, int length) {
    for (size_t i = 0; i < length; i++)
    {
        maxHeap(arr, length - i);
        swap(arr, 0, (length - 1 - i));
    }
}

int* bigArray(long size) {
    int* arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    // int arr[] = {10, 6, 7, 5, 15, 17, 12};
    // // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // int length = 7;
    // std::cout << printArr(arr, length) << std::endl;
    // mergeSort(arr, length);
    // std::cout << printArr(arr, length) << std::endl;
    int size = 100000;
    int* arr = bigArray(size);
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, size);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    return 0;
}
