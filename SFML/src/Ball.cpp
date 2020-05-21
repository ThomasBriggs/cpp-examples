#include "Ball.h"

Ball::Ball(int radius, sf::Vector2i position) {
	this->radius = radius;
	this->x = position.x;
	this->y = position.y;
	this->shape = sf::CircleShape(radius);
}

sf::Drawable* Ball::draw()
{
	return &this->shape;
}
