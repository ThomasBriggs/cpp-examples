#include "Menu.h"
#include <string>
#include <iostream>
#include "CursesUtil.h"

Menu::Menu(WINDOW* win, const char* title, Alighnemnt a) : win(win), title(title)
{
    box(win, 0, 0);
    mvwprintw(win, 0, 1, this->title.c_str());

    switch (a)
    {
    case CENTER:
        this->alignFunc = centerText;
        break;
    case LEFT:
        this->alignFunc = leftText;
        break;
    case RIGHT:
        this->alignFunc = rightText;
        break;
    }
}

void Menu::addItem(const char* text, std::function<void()> event)
{
    this->items.emplace_back(this->win, text, this->items.size() + 1, 0, event);
}

void Menu::draw(bool refresh)
{
    if (!this->items.empty())
    {
        for (auto&& i : this->items) { i.draw(this->alignFunc); }
        this->items[this->curSelected].drawActive(this->alignFunc);
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

void Menu::select() { this->items[this->curSelected].event(); }