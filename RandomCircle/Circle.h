#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Circle : public sf::CircleShape
{
public:
    Circle() : sf::CircleShape()
    {
        std::cout << "Created a circle" << '\n';
    }
};

#endif