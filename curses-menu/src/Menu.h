#pragma once
#include "MenuItem.h"
#include <vector>
#include <ncurses.h>

class Menu
{
public:
    enum Alighnemnt {CENTER = 0, LEFT = 1, RIGHT = 2};

private:
    typedef std::vector<MenuItem> MenuItemList;
    MenuItemList items;
    WINDOW * win;
    std::string title;
    Alighnemnt align;
    int curSelected = 0;

public:
    Menu(WINDOW * win, const char* title, Alighnemnt = CENTER);
    void draw(bool refresh = false);
    void addItem(const char* text);
    void next();
    void prev();
};






