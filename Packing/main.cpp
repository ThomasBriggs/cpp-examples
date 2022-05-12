#include <iostream>


// #pragma pack(4)
struct S {
    long i;     // size     8
    char c;     // size     1
    char c1;    // size     1
    char c2;    // size     1
    char c3;    // size     1
    char c5;    // size     1
    int i1;     // size     4
    // char c4;    // size     1
    //             // Total    15
};

#pragma pack(1)
struct P1S {
    long i;      // size     4
    char c;     // size     1
    char c1;    // size     1
    int i1;     // size     4
    char c2;    // size     1
                // Total    11
};

#pragma pack(2)
struct P2S {
    int i;      // size     4
    char c;     // size     1
    char c1;    // size     1
    int i1;     // size     4
    char c2;    // size     1
                // Total    11
};

int main()
{
    S s = S();
    P1S p1s = P1S();
    P2S p2s = P2S();

    std::cout << "Size of s: " << sizeof(s) << '\n';
    // std::cout << "Size of p1s: " << sizeof(p1s) << '\n';
    // std::cout << "Size of p2s: " << sizeof(p2s) << '\n';
    return 0;
}
