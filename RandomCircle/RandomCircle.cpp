#include "RandomCircle.h"

randomCircle::randomCircle(int x, int y, int minSize, int maxSize, int num) : num{num}
{
    this->size_dist =  std::uniform_int_distribution<int>(minSize, maxSize);
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

void randomCircle::generateCircle()
{
    if (this->index > 199)
        this->index = 0;
    sf::CircleShape &c = this->shapeList.at(this->index);
    c.setRadius(this->getSize());
    c.setFillColor(sf::Color(this->getColor()));
    c.setPosition(this->getPos());
    this->index++;
}


std::array<sf::CircleShape, 200> randomCircle::getShapeList()
{
    return this->shapeList;
}
