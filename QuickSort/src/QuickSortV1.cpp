#include <iostream>
#include <cstdlib>

// void quickSort(int start, int end, int *array)
// {
//     if (end > start)
//     {
//         int left = start;
//         int right = end;
//         int middle = array[(left + right) / 2];

//         do
//         {
//             while (array[left] < middle)
//             {
//                 left++;
//             }

//             while (array[right] > middle)
//             {
//                 right--;
//             }

//             int temp = array[left];
//             array[left] = array[right];
//             array[right] = temp;

//         } while (left != right);

//         quickSort(start, left - 1, array);
//         quickSort(right + 1, end, array);
//     }
// }

void print(int* array, int length) {
    char* output;
    for (int i = 0; i < length; i++) {
        output += array[i];
    }
    std::cout << "Hello" << std::endl;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    int test[] = {58, 11, 75, 3, 53, 63, 9, 94, 75, 35};
    print(test, 10);
    return 0;
    
}
