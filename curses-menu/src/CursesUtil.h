#pragma once
#include <ncurses.h>
#include <cstring>

void centerText(WINDOW* w, int y, const char* s)
{
    int start_x = (getmaxx(w)/ 2) - (std::strlen(s) / 2);
    wmove(w, y, start_x);
    wprintw(w, s);
}

void rightText(WINDOW * w, int y, const char* s)
{
    wmove(w, y, getmaxx(w) - std::strlen(s) - 1);
    wprintw(w, s);
}

void leftText(WINDOW * w, int y, const char* s)
{
    wmove(w, y, 1);
    wprintw(w, s);
}