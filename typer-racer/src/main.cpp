#include <curses.h>
#include <iostream>
#include "display.h"
#include "file.h"
#include <cctype>
#include <algorithm>

WINDOW* getInputWin()
{
    WINDOW* win = newwin(3, getmaxx(stdscr), 0, 0);
    box(win, 0, 0);
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Input");
    wattroff(win, A_BOLD);
    return win;
}

WINDOW* getPromptWin()
{
    WINDOW* win = newwin(getmaxy(stdscr) - 3, getmaxx(stdscr), 3, 0);
    box(win, 0, 0);
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Prompt");
    wattroff(win, A_BOLD);
    return win;
}

int main()
{
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();

    WINDOW* inputWin = getInputWin();
    WINDOW* promptWin = getPromptWin();
    refresh();
    wrefresh(inputWin);
    wrefresh(promptWin);

    auto words = getRandomWords
    (
        "/home/thomas/Documents/cpp-examples/typer-racer/src/words.txt",
        50
    );

    displayWords(promptWin, words);
    wrefresh(promptWin);

    bool active = true;
    std::vector<std::string> inputWords(words.size());
    int input;
    int curWord = 0;
    while (active)
    {
        input = getch();
        if (std::isalpha(input) || std::isdigit(input))
        {
            inputWords[curWord] += input;
            displayInput(inputWin, inputWords[curWord]);
        }
        else if (input == 127)
        {
            if (inputWords[curWord].empty()) curWord = std::max(0, curWord - 1);
            else (inputWords[curWord].pop_back());
            displayInput(inputWin, inputWords[curWord]);
        }
        else if (input == ' ')
        {
            curWord += 1;
            displayInput(inputWin, inputWords[curWord]);
        }
        wrefresh(inputWin);
    }
    return 0;
}

