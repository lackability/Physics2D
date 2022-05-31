#pragma once
#include "_Math.h"
#include "Object.h"
#include "Environment.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Collision
{
	private:

	public:
		bool Object2Object(Object& obj1, Object& obj2);
		bool inAir(Object& obj1, Environment& environment, sf::RenderWindow& window);
		bool floorCollision(Object& obj1, Environment& env);
		bool borderCollision(sf::RenderWindow& window, Object& obj1);
		
		//for example, if a box touched another box moving at different speeds
		//
};

