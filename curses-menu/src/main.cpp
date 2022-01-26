#include <ncurses.h>
#include <cstring>
#include <vector>
#include "MenuItem.h"

void centerText(WINDOW* w, int y, char* s)
{
    int max_x = getmaxx(w);

    int n = std::strlen(s);
    int start_x = max_x / 2 - n / 2 - 4;
    wmove(w, y, start_x);
    wprintw(w, "    ");
    wprintw(w, s);
    wprintw(w, "    ");
}

void menuItem(WINDOW* win, int y, char* s, bool active)
{
    if (active) wattron(win, A_STANDOUT);
    centerText(win, y, s);
    wattroff(win, A_STANDOUT);
}

void init()
{
    WINDOW* win = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    box(win, 0, 0);
    refresh();
    mvwprintw(win, 0, 1, "MENU");
    wrefresh(win);
    std::vector<MenuItem> menuItems;
    menuItems.emplace_back(win, "test", 1, 1);
    menuItems.emplace_back(win, "Test 2", 2, 1);
    menuItems[1].toggleActive();
    for (auto&& i : menuItems) { i.draw(); }
    wrefresh(win);
    move(1, 1);
}

int main()
{

    initscr();
    noecho();
    cbreak();
    curs_set(0);

    init();

    while (getch() != 10);
    endwin();
    return 0;
}
