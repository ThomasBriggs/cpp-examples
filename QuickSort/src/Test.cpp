#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    for (size_t i = 1; i < argc; i++)
    {
        cout << *((int *)&argv[i]) << endl;
    }
    return 0;
}
