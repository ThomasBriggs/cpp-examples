#include <iostream>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    auto list = LinkedList();
    list.append(10);
    list.append(20);
    list.append(30);

    list.insert(0, 99);

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << list.get(i) << std::endl;
    }
}
