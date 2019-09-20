#include <vector>

namespace prime
{
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

std::vector<int> primeGenerator(int n, int start_num=2) {
    std::vector<int> prime_array(n);
    int i = 0;
    int test_number = start_num;
        
    while (i < n) {
        if (isPrime(test_number) == true) {
            prime_array[i] = test_number;
            i++;
        }
        test_number++;
    }
    return prime_array;
}
}
