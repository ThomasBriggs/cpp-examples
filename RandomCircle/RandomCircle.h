#pragma once

#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Circle.h"

class randomCircle
{
private:
    std::random_device rng = std::random_device();
    std::uniform_int_distribution<int> size_dist = std::uniform_int_distribution<int>(25, 50);
    std::uniform_int_distribution<int> x_dist;
    std::uniform_int_distribution<int> y_dist;
    std::uniform_int_distribution<uint32_t> color_dist = std::uniform_int_distribution<uint32_t>(0, UINT32_MAX);
    int getSize();
    sf::Vector2f getPos();
    uint32_t getColor();

public:
    randomCircle(int windowX, int windowY);
    void generateCircle(std::vector<Circle> &list);
};