#include "display.h"
#include <curses.h>

void displayWords(WINDOW* win, std::vector<std::string> words)
{
    u_int min_y = 1, min_x = 1, max_x = getmaxx(win) - 1;
    wmove(win, min_y, min_x);
    for (auto&& i : words)
    {
        if (getcurx(win) + i.size() < max_x) { wprintw(win, (i + ' ').c_str()); }
        else { mvwprintw(win, getcury(win) + 1, min_x, (i + ' ').c_str()); }
    }
}

void displayInput(WINDOW* win, const std::string& s)
{
    clearInput(win);
    wmove(win, 1, 1);
    wprintw(win, s.c_str());
}


void clearInput(WINDOW* win)
{
    wclear(win);
    box(win, 0, 0);
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Input");
    wattroff(win, A_BOLD);
}