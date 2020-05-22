#include "Ball.h"

Ball::Ball(int radius, int x, int y) {
	this->radius = radius;
	this->shape = sf::CircleShape(radius);
	this->setPosition(x, y);
}

sf::Drawable& Ball::draw()
{
	this->update();
	return this->shape;
}

void Ball::setX(int x)
{
	this->x = x;
}

void Ball::setY(int y)
{
	this->y = y;
}

void Ball::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Ball::setColour(sf::Color colour)
{
	this->shape.setFillColor(colour);
}

int Ball::getRadius()
{
	return this->radius;
}

int Ball::getX()
{
	return this->x;
}

int Ball::getY()
{
	return this->y;
}

void Ball::incSize(int amount)
{
	this->radius += amount;
}

void Ball::decSize(int amount)
{
	this->radius -= amount;
}

void Ball::boundsCheck(sf::RenderWindow &window)
{
	sf::Vector2u windowSize = window.getSize();
	if (this->x < 0)
		this->x = 0;
	if (this->y < 0)
		this->y = 0;
	if (this->x > windowSize.x)
		this->x = windowSize.x;
	if (this->y > windowSize.y)
		this->y = windowSize.y;
}

void Ball::update()
{
	this->shape.setPosition(sf::Vector2f(this->x, this->y));
	this->shape.setRadius(radius);
	this->shape.setOrigin(radius, radius);
}

