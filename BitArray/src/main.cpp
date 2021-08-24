#include <cstring>
#include <iostream>

int main()
{
    uint32_t* i = new uint32_t[2];
    memset(i, 0xFF, sizeof(i[0])*2);
    std::cout << i[1] << '\n';
}
