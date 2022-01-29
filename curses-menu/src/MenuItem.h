#pragma once
#include <ncurses.h>
#include <string>
#include <functional>

class MenuItem
{
private:
    std::string text;
    WINDOW* win;
    int y, x;
    std::function<void()> event;
    typedef std::function<void(WINDOW* win, int y, const char* s)> alignFunc;
    void draw(alignFunc);
    void drawActive(alignFunc);

public:
    MenuItem(WINDOW* win, std::string text, int y, int x, std::function<void()> event, bool padding = true);
    friend class Menu;
};