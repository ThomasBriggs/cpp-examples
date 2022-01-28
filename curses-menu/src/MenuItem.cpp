#include "MenuItem.h"
#include "CursesUtil.h"


MenuItem::MenuItem(WINDOW* win, std::string text, int y, int x, bool padding)
    : text(text), win(win), y(y), x(x)
{
    if (padding)
    {
        this->text.insert(this->text.begin(), 4, ' ');
        this->text.append("    ");
    }
}

void MenuItem::draw() { centerText(this->win, this->y, this->text.c_str()); }

void MenuItem::drawActive()
{
    wattron(this->win, A_STANDOUT);
    this->draw();
    wattroff(this->win, A_STANDOUT);
}
