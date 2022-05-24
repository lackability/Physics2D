#pragma once
#include "Environment.h"
#include "Object.h"
#include "_Math.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Collision
{
	private:

	public:
		void Object2Object(Object obj1, Object obj2);
		void baseCollision(Object& obj1);
		void borderCollision(sf::RenderWindow& window, Object& obj1);
		
		//for example, if a box touched another box moving at different speeds
		//
};

