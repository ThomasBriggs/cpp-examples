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

    sf::CircleShape circ(10.f);
    circ.setOrigin(circ.getRadius(), circ.getRadius());
    circ.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    int lineWidth = 2;
    sf::RectangleShape xLine(sf::Vector2f(window.getSize().x, lineWidth));
    xLine.setFillColor(sf::Color::Blue);
    xLine.setPosition(0, window.getSize().y / 2);

    sf::RectangleShape yLine(sf::Vector2f(lineWidth, window.getSize().y));
    yLine.setFillColor(sf::Color::Blue);
    yLine.setPosition(window.getSize().x / 2, 0);

    sf::Font font;
    font.loadFromFile("..\\fonts\\OpenSans-Regular.ttf");

    sf::Text mouseCoords;
    mouseCoords.setFont(font);
    mouseCoords.setString("Hello");
    mouseCoords.setPosition(0, 0);

    sf::Text pointerCoords;
    pointerCoords.setFont(font);
    pointerCoords.setString("World");
    pointerCoords.setPosition(0, 50);

    // run the program as long as the window is open
    bool mouseDown;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved && window.hasFocus())
            {
                mouseCoords.setString(std::to_string(sf::Mouse().getPosition(window).x) + "," + std::to_string(sf::Mouse().getPosition(window).y));
                pointerCoords.setString(std::to_string((int)circ.getPosition().x) + "," + std::to_string((int)circ.getPosition().y));
                xLine.setPosition(0, sf::Mouse().getPosition(window).y - lineWidth / 2);
                yLine.setPosition(sf::Mouse().getPosition(window).x - lineWidth / 2, 0);
                circ.setPosition(sf::Mouse().getPosition(window).x, sf::Mouse().getPosition(window).y);
            }
        }
        window.clear(sf::Color::Black);
        window.draw(xLine);
        window.draw(yLine);
        window.draw(circ);
        window.draw(mouseCoords);
        window.draw(pointerCoords);
        window.display();

    }

    return 0;
}