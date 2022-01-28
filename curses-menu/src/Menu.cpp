#include "Menu.h"
#include <string>
#include <iostream>

Menu::Menu(WINDOW* win, const char* title, Alighnemnt a) : win(win), title(title), align(a)
{
    box(win, 0, 0);
    mvwprintw(win, 0, 1, this->title.c_str());
}


void Menu::addItem(const char* text)
{
    this->items.emplace_back(this->win, text, this->items.size() + 1, 0, true);
}

void Menu::draw(bool refresh)
{
    if (!this->items.empty())
    {
        for (auto&& i : this->items) { i.draw(); }
        this->items[this->curSelected].drawActive();
    }
    if (refresh) wrefresh(this->win);
}

void Menu::next()
{
    this->curSelected = ((this->curSelected + 1) % this->items.size());
    this->draw();
}

void Menu::prev()
{
    this->curSelected = this->curSelected - 1 < 0 ? this->items.size() - 1 : this->curSelected - 1;
    this->draw();
}