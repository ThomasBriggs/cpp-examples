#pragma once

#include <curses.h>
#include <vector>
#include <string>

void displayWords(WINDOW* win, std::vector<std::string> words, int currentWord);
void displayInput(WINDOW* win, const std::string& s);
void clearInput(WINDOW * win);
void drawInput(WINDOW * win);
WINDOW* getInputWin();
WINDOW* getPromptWin();