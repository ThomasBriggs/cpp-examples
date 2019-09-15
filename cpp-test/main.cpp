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

int* printPrimes(int n) {
    int found_primes = 0;
    int i  = 2;
    int prime_array[n];
    while (found_primes < n) {
        if (isPrime(i) == true) {
            
        }
    }
}

int main() {

    for (int i = 3; i < 10; i++) {
        cout << "Number: " << i << endl;
        cout << isPrime(i) << endl;
    }

    return 0;

}