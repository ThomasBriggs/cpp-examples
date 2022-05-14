#include "pHash.h"
#include <iostream>

int main()
{
    char path[] = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro_original.jpg";
    ulong64 hash = 0;
    char path1[] = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro_mod.jpg";
    ulong64 hash1 = 0;
    char path2[] = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro1.jpg";
    ulong64 hash2 = 0;
    char path3[] = "/home/thomas/Documents/cpp-examples/pHash/imgs/diff.jpg";
    ulong64 hash3 = 0;

    ph_dct_imagehash(path, hash);
    std::cout << "Hash 1: " << hash << '\n';
    ph_dct_imagehash(path1, hash1);
    std::cout << "Hash 2: " << hash1 << '\n';
    ph_dct_imagehash(path2, hash2);
    std::cout << "Hash 3: " << hash2 << '\n';
    ph_dct_imagehash(path3, hash3);
    std::cout << "Hash 4: " << hash3 << '\n';

    std::cout << '\n';

    std::cout << "Ham Dist between 1 and 2: " << ph_hamming_distance(hash, hash1) << '\n';
    std::cout << "Ham Dist between 1 and 3: " << ph_hamming_distance(hash, hash2) << '\n';
    std::cout << "Ham Dist between 1 and 4: " << ph_hamming_distance(hash, hash3) << '\n';
}