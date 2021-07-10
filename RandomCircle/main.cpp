#include <SFML/Graphics.hpp>
#include <vector>
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
        }

        auto time = clock.getElapsedTime();
        if (time.asMilliseconds() >= 100)
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
