#pragma once
#include <ncurses.h>
#include <string>

class MenuItem
{
private:
    std::string text;
    WINDOW* win;
    int y, x;
    MenuItem(WINDOW* win, std::string text, int y, int x, bool padding = true);
    typedef void(*alignFunc)(WINDOW * win, int y, const char* s);
    void draw(alignFunc);
    void drawActive(alignFunc);
};