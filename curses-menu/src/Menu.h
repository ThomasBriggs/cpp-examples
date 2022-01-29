#pragma once
#include <vector>
#include <ncurses.h>
#include <string>
#include "MenuItem.h"
#include <functional>


class Menu
{
public:
    enum Alighnemnt { CENTER = 0, LEFT = 1, RIGHT = 2 };

private:
    typedef std::vector<MenuItem> MenuItemList;
    MenuItemList items;
    WINDOW* win;
    std::string title;
    int curSelected = 0;
    MenuItem::alignFunc alignFunc;

public:
    Menu(WINDOW* win, const char* title, Alighnemnt = CENTER);
    void draw(bool refresh = false);
    void addItem(const char* text, std::function<void()>event = [](){;});
    void next();
    void prev();
    void select();
};






