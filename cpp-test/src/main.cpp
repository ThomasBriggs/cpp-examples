
#include <iostream>
#include <vector>
#include "sort.h"

namespace fib {
    
    int fibGen(int n) {
        int num = 1;
        int prev_num = 0;
        while (n > 0) {
            int temp = num;
            num = num+prev_num;
            prev_num = temp;
            n--;
        }
        return prev_num;
    }

    int recFibGen(int n) {
        if (n < 2) {
            return n;
        }else {
            return recFibGen(n-2)+ recFibGen(n-1);
        }
    }
}

namespace sort {

    void bubbleSort(int sort_array[], int length) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - 1 - i; j++) {
                if (sort_array[j] > sort_array[j+1]) {
                    int temp = sort_array[j];
                    sort_array[j] = sort_array[j+1];
                    sort_array[j+1] = temp;
                }
            }      
        }    
    }

    void insertionSort(int sort_array[], int length) {
        for (int i = 1; i < length; i++)
        {
            while (sort_array[i] < sort_array[i-1]) {

            }
        }
        
    }
}

using namespace fib;
using namespace std;


int main() {
    vector<int> arr = primeGenerator(100);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;

    cout << fibGen(5) << endl;
    cout << fibGen(10) << endl;
    
}
