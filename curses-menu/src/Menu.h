#pragma once
#include <vector>
#include <ncurses.h>
#include <string>

class MenuItem
{
private:
    std::string text;
    WINDOW* win;
    int y, x;
    typedef void(*alignFunc)(WINDOW* win, int y, const char* s);
    void draw(alignFunc);
    void drawActive(alignFunc);

public:
    MenuItem(WINDOW* win, std::string text, int y, int x, bool padding = true);
    friend class Menu;
};

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
    void addItem(const char* text);
    void next();
    void prev();
};






