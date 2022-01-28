#include <ncurses.h>
#include <cstring>
#include <set>
#include "Menu.h"

int main()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    WINDOW* win = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    refresh();
    Menu menu(win, "Menu");
    menu.addItem("Item 1");
    menu.addItem("Item 2");
    menu.addItem("Item 3");

    menu.draw(true);

    int input;
    std::set<char> up{ 'w', 'k' };
    std::set<char> down{ 's', 'j' };
    while ((input = getch()) != (int)'\n')
    {
        if (up.contains(input)) menu.prev();
        else if (down.contains(input)) menu.next();
        wrefresh(win);
    }
    endwin();
    return 0;
}
