#include <ncurses.h>
#include <cstring>
#include <set>
#include "Menu.h"
#include <iostream>
#include <string>

void log(const char* s)
{
    std::string cmd = "echo \"\" >> output.log";
    cmd.insert(5, s);
    system(cmd.c_str());
}

int main()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    WINDOW* win = newwin(getmaxy(stdscr), getmaxx(stdscr) / 2, 0, getmaxx(stdscr) / 2);

    refresh();
    Menu menu(win, "Menu", Menu::CENTER);
    menu.addItem("Item 1", [](){log("Item 1");});
    menu.addItem("Item 2", [](){log("Item 2");});
    menu.addItem("Item 3", [](){log("Item 3");});

    menu.draw(true);

    int input;
    std::set<char> up{ 'w', 'k' };
    std::set<char> down{ 's', 'j' };
    while ((input = getch()) != (int)'\n')
    {
        if (up.contains(input)) menu.prev();
        else if (down.contains(input)) menu.next();
        else if (input == ' ') menu.select();
        wrefresh(win);
    }
    endwin();
    return 0;
}
