#include <curses.h>
#include <iostream>
#include "display.h"
#include "file.h"
#include <cctype>
#include <algorithm>



int main()
{
    initscr();
    use_default_colors();
    assume_default_colors(-1, -1);
    cbreak();
    keypad(stdscr, true);
    noecho();
    start_color();

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
    wmove(inputWin, 1, 1);
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
            displayInput(inputWin,inputWords[curWord]);
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