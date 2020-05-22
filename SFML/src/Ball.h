#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::CircleShape shape;
	int radius;
	int x;
	int y;
	sf::Color colour;

	void update();


public:
	Ball(int radius, int x, int y);
	sf::Drawable& draw();
	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
	void setColour(sf::Color colour);
	int getRadius();
	int getX();
	int getY();
	static const int MAX_SPEED = 10;
	void incSize(int amount);
	void decSize(int amount);
	void boundsCheck(sf::RenderWindow& window);
};

