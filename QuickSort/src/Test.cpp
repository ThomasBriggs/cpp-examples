#include <iostream>
#include <string>

using namespace std;

int test(int* input) {
    return *input;
}

int main(int argc, char const *argv[])
{
    string test = "Hello";
    test += " World";
    cout << test << endl;
}
