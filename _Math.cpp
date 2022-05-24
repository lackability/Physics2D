#include "_Math.h"

sf::Vector2f _Math::normalize(sf::Vector2f vector)
{
    float len = length(vector);
    return { vector.x / len, vector.y / len };
}

float _Math::length(sf::Vector2f vector)
{
    return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}
