#include <iostream>
using namespace std;

int main ()
{
    int factor1 = 3;
    int factor2 = 5;
    bool found = false;
    string factor1_word = "Fizz";
    string factor2_word = "Buzz";
    int n = 100;
    for (int i = 1; i < n+1; i++)
    {
        if (i % factor1 == 0)
        {
            cout << factor1_word;
            found = true;
        }
        if (i % factor2 == 0)
        {
            cout << factor2_word;
            found = true;
        }
        if (found == 0)
        {
            cout << i;
        }
        cout << endl;
        found = false;
    }
    return 0;
}