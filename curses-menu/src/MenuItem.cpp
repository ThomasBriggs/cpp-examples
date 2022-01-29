#include "MenuItem.h"

MenuItem::MenuItem(WINDOW* win, std::string text, int y, int x,std::function<void()> event, bool padding)
    : text(text), win(win), y(y), x(x), event(event)
{
    if (padding)
    {
        this->text.insert(this->text.begin(), 4, ' ');
        this->text.append("    ");
    }
}

void MenuItem::draw(alignFunc func)
{
    func(this->win, this->y, this->text.c_str());
}

void MenuItem::drawActive(alignFunc func)
{
    wattron(this->win, A_STANDOUT);
    this->draw(func);
    wattroff(this->win, A_STANDOUT);
}