
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

int main() {

    cout << fib::recFibGen(10) << endl;
    
    return 0;
}
