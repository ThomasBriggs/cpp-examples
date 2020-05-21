#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::CircleShape shape;
	int radius;
	int x, y;
	sf::Color colour;

public:
	explicit Ball(int radius, sf::Vector2i position);
	sf::Drawable* draw();
};

