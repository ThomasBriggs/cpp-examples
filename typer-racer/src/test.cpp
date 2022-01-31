#include <string>
#include <iostream>
#include <curses.h>

int main(int argc, char const *argv[])
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    int input = getch();
    std::cout << input << '\n';
    // if (input == KEY_)
    // {
    //     std::cout << "Yes" << '\n';
    // } else {std::cout << "No" << '\n';}
}

