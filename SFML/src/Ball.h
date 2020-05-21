#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::CircleShape shape;
	int radius;
	sf::Color colour;

public:
	Ball(int radius, int x, int y);
	sf::Drawable& draw();
	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
};

