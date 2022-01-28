#pragma once
#include <ncurses.h>
#include <string>

class MenuItem
{
private:
    std::string text;
    WINDOW* win;
    int y, x;

public:
    MenuItem(WINDOW* win, std::string text, int y, int x, bool padding = true);
    void draw();
    void drawActive();
};