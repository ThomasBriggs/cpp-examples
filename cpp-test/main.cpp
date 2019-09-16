#include <iostream>

using namespace std;

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

int* primeGenerator(int n) {
    int i = 0;
    int test_number  = 2;

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

int* testFunction() {

    int * arr = new int[5];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = 1;
    }
    return arr;
}

int main() {

    int * test = primeGenerator(5);
    for (int i = 0; i < 5; i++)
    {
        cout << test[i] << endl;
    }
    
    return 0;
}
