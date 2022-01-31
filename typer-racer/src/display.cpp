#include "display.h"
#include <curses.h>

void displayWords(WINDOW* win, std::vector<std::string> words, int currentWord)
{
    init_pair(5, COLOR_BLUE, -1);
    u_int min_y = 1, min_x = 1, max_x = getmaxx(win) - 1;
    wmove(win, min_y, min_x);
    auto&& curWord = words[0];
    for(int i = 0; i < words.size(); i++)
    {
        curWord = words[i];
        if (!(getcurx(win) + curWord.size() < max_x)) { wmove(win, getcury(win) + 1, min_x); }
        if (i == currentWord) wattron(win, COLOR_PAIR(5));
        wprintw(win, (curWord + ' ').c_str());
        wattroff(win, COLOR_PAIR(5));
    }
}

void displayInput(WINDOW* win, const std::string& s)
{
    clearInput(win);
    wmove(win, 1, 1);
    wprintw(win, s.c_str());
}


void clearInput(WINDOW* win)
{
    wclear(win);
    drawInput(win);
}

WINDOW* getInputWin()
{
    WINDOW* win = newwin(3, getmaxx(stdscr), 0, 0);
    drawInput(win);
    return win;
}

WINDOW* getPromptWin()
{
    WINDOW* win = newwin(getmaxy(stdscr) - 3, getmaxx(stdscr), 3, 0);
    init_pair(3, COLOR_YELLOW, -1);
    wattron(win, COLOR_PAIR(3));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(3));
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Prompt");
    wattroff(win, A_BOLD);
    return win;
}

void drawInput(WINDOW * win)
{
    init_pair(2, COLOR_CYAN, -1);
    wattron(win, COLOR_PAIR(2));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(2));
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Input");
    wattroff(win, A_BOLD);
}