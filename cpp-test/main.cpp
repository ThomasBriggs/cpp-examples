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
    int found_primes = 0;
    int test_number  = 2;

    int prime_array[n];
    
    while (found_primes < n) {
        if (isPrime(test_number) == true) {
            prime_array[i] = test_number;
        }
        i++;
        test_number++;
    }
    return prime_array;
}

int main() {

    int* array;
    array = primeGenerator(10);
    for (int i = 0; i < 10; i++)
    {
        cout << array[0] << endl;
    }
    
    return 0;

}
