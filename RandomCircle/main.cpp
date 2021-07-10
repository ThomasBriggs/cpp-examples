#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Circle.h"
#include "RandomCircle.h"

int main(int argc, char const *argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window", 7U, settings);

    std::vector<Circle> shapeList;

    randomCircle rCirc(window.getSize().x, window.getSize().y);

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
            rCirc.generateCircle(shapeList);
            clock.restart();
        }

        window.clear(sf::Color::Black);
        for (auto &&i : shapeList)
        {
            window.draw(i);
        }
        window.display();
    }
    return 0;
}
