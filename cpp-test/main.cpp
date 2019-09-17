
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

    int* primeGenerator(int n, int start_num) {
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
        int * output = primeGenerator(n, 2);
        for (int i = 0; i < n; i++)
        {
            cout << output[i] << endl;
        }
    }
};

int* testFunction() {

    int * arr = new int[5];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = 1;
    }
    return arr;
}

int main() {

    time_t start, end;
    start = clock();
    int * primes = prime::primeGenerator(100, 10000000);
    for (int i = 0; i < 20; i++)
    {
        cout << primes[i] << endl;
    }
    
    end = clock();

    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Time " << fixed << time_taken; 
    cout << endl;
    
    return 0;
}
