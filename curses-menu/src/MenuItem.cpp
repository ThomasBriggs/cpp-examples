#include "MenuItem.h"


MenuItem::MenuItem(WINDOW* win, std::string text, int y, int x)
    : text(text), active(false), win(win), y(y), x(x)
{}

void MenuItem::setActve(bool state) { this->active = state; }

bool MenuItem::getActive() { return this->active; }

void MenuItem::draw()
{
    if (this->active)
    {
        wattron(this->win, A_STANDOUT);
        mvwprintw(this->win, this->y, this->x, this->text.c_str());
        wattroff(this->win, A_STANDOUT);
    }
    else
    {
        mvwprintw(this->win, this->y, this->x, this->text.c_str());
    }
}

bool MenuItem::toggleActive()
{
    this->active = !this->active;
    return this->active;
}