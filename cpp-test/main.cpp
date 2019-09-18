
#include <iostream>

using namespace std;

namespace prime {

    bool isPrime(int n) {
    
        int n_counter = n/2;

        while (n_counter > 1) {
            if ((n % n_counter) == 0) {
                return false;
            }
            n_counter--; 
        }
        return true;
    }

    int* primeGenerator(int n, int start_num=2) {

        int i = 0;
        int test_number = start_num;

        int * prime_array = new int[n];
        
        while (i < n) {
            if (isPrime(test_number) == true) {
                prime_array[i] = test_number;
                i++;
            }
            test_number++;
        }
        return prime_array;
    }

    void printPrimes(int n) {
        int * output = primeGenerator(n);
        for (int i = 0; i < n; i++)
        {
            cout << output[i] << endl;
        }
    }
};

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

    void bubbleSort(int * sort_array, int length) {
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
}

int main() {

    int arr[] = {5,2,6,4,9,11,3,54,84,95,12,45};
    int arr_length = sizeof(arr)/sizeof(arr[0]);
    sort::bubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < arr_length; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}
