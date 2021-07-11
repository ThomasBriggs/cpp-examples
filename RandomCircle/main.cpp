#include <SFML/Graphics.hpp>
#include <iostream>
#include "RandomCircle.h"

int main(int argc, char const *argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window", 7U, settings);
    window.setFramerateLimit(75);

    randomCircle rCirc(window.getSize().x, window.getSize().y, 10, 25, 200);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
            if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Right)
                {
                    auto view = sf::View();
                    view.setSize(window.getView().getSize());
                    view.setCenter(window.getView().getCenter());
                    view.setRotation(window.getView().getRotation() + 10.f);
                    window.setView(view);
                }
            }
        }

        if (clock.getElapsedTime().asMilliseconds() >= 100)
        {
            rCirc.generateCircle();
            clock.restart();
        }

        window.clear(sf::Color::Black);
        for (auto &&i : rCirc.getShapeList())
        {
            window.draw(i);
        }
        window.display();
    }
    return 0;
}
