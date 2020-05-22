#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <string>
#include "Ball.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
	window.setVerticalSyncEnabled(true);
	window.clear(sf::Color::Black);

	sf::Image icon;
	// icon.loadFromFile("/images/teddy_bear_clear.png");
	// window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	bool mouseDown;
	Ball ball = Ball(50, window.getSize().x / 2, window.getSize().y / 2);
	ball.setColour(sf::Color::Blue);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			ball.setX(ball.getX() - Ball::MAX_SPEED);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			ball.setX(ball.getX() + Ball::MAX_SPEED);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			ball.setY(ball.getY() - Ball::MAX_SPEED);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			ball.setY(ball.getY() + Ball::MAX_SPEED);

		//Size change
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
			ball.incSize(10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
			ball.decSize(10);


		window.clear(sf::Color::Black);
		ball.boundsCheck(window);
		window.draw(ball.draw());
		window.display();
	}

	return 0;
}