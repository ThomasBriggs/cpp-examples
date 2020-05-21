#include "Ball.h"

Ball::Ball(int radius, int x, int y) {
	this->radius = radius;
	this->shape = sf::CircleShape(radius);
	this->shape.setPosition(sf::Vector2f(x, y));
}

sf::Drawable& Ball::draw()
{
	return this->shape;
}

void Ball::setX(int x)
{
	this->shape.setPosition(sf::Vector2f(x, this->shape.getPosition().y));
}

void Ball::setY(int y)
{
	this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x, y));
}

void Ball::setPosition(int x, int y)
{
	this->shape.setPosition(sf::Vector2f(x, y));
}

