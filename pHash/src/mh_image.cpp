#include <iostream>
#include "pHash.h"

int main()
{
    char path[] = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro_original.jpg";
    int N = 0;
    auto hash = ph_mh_imagehash(path, N);

    char path1[] = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro_mod.jpg";
    int N1 = 0;
    auto hash1 = ph_mh_imagehash(path1, N1);

    char path2[] = "/home/thomas/Documents/cpp-examples/pHash/imgs/astro1.jpg";
    int N2 = 0;
    auto hash2 = ph_mh_imagehash(path2, N2);

    std::cout << ph_hammingdistance2(hash, N, hash1, N1) << '\n';
    std::cout << ph_hammingdistance2(hash, N, hash2, N2) << '\n';

    return 0;
}
