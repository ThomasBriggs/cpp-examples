// #include <curses.h>
#include <iostream>
#include "words.h"

// WINDOW * getInputWin()
// {
//     WINDOW * win = newwin(3, getmaxx(stdscr), 0, 0);
//     box(win, 0, 0);
//     wattron(win, A_BOLD);
//     mvwprintw(win, 0, 1, "Input");
//     wattroff(win, A_BOLD);
//     return win;
// }

// WINDOW * getPromptWin()
// {
//     WINDOW * win = newwin(getmaxy(stdscr)-3, getmaxx(stdscr), 3, 0);
//     box(win, 0, 0);
//     wattron(win, A_BOLD);
//     mvwprintw(win, 0, 1, "Prompt");
//     wattroff(win, A_BOLD);
//     return win;
// }

// int main()
// {
//     initscr();
//     cbreak();

//     WINDOW * inputWin = getInputWin();
//     WINDOW * promptWin = getPromptWin();
//     refresh();
//     wrefresh(inputWin);
//     wrefresh(promptWin);

//     getch();
//     return 0;
// }

int main()
{
    std::cout << words.size() << std::endl;;
    return 0;
}