#include "RandomCircle.h"

randomCircle::randomCircle(int x, int y)
{
    this->x_dist = std::uniform_int_distribution<int>(0, x);
    this->y_dist = std::uniform_int_distribution<int>(0, y);
}

int randomCircle::getSize()
{
    return this->size_dist(this->rng);
}

sf::Vector2f randomCircle::getPos()
{
    return sf::Vector2f(this->x_dist(this->rng), this->y_dist(this->rng));
}

uint32_t randomCircle::getColor()
{
    return this->color_dist(this->rng);
}

void randomCircle::generateCircle(std::vector<Circle> &list)
{
    list.emplace_back(Circle());
    Circle &c = list.back();
    c.setRadius(this->getSize());
    c.setFillColor(sf::Color(this->getColor()));
    c.setPosition(this->getPos());
    if (list.size() > 200)
        list.erase(list.begin());
}