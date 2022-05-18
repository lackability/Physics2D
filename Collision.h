#pragma once
#include "Environment.h"
#include "Object.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Collision
{
	public:
		void Object2Object(sf::CircleShape obj1, sf::CircleShape obj2);
		void baseCollision(sf::CircleShape obj1, sf::RectangleShape base);
		
		//for example, if a box touched another box moving at different speeds
		//
};

