#pragma once

#include <random>
#include <array>
#include <SFML/Graphics.hpp>

class randomCircle
{
private:
    std::array<sf::CircleShape, 200> shapeList;
    int index = 0;
    int num;
    std::random_device rng = std::random_device();
    std::uniform_int_distribution<int> size_dist;
    std::uniform_int_distribution<int> x_dist;
    std::uniform_int_distribution<int> y_dist;
    std::uniform_int_distribution<uint32_t> color_dist = std::uniform_int_distribution<uint32_t>(0, UINT32_MAX);
    int getSize();
    sf::Vector2f getPos();
    uint32_t getColor();

public:
    randomCircle(int windowX, int windowY, int minSize, int maxSize, int num);
    void generateCircle();
    std::array<sf::CircleShape, 200> getShapeList();
};