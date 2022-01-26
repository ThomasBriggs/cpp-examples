#pragma once
#include <ncurses.h>
#include <string>

class MenuItem
{
private:
    std::string text;
    bool active;
    WINDOW* win;
    int y, x;

public:
    MenuItem(WINDOW* win, std::string text, int y, int x);
    void setActve(bool);
    bool getActive();
    bool toggleActive();
    void draw();
};