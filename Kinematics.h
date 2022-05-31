#pragma once

#include "Collision.h"
#include <cmath>
#include <SFML/Graphics.hpp>

class Kinematics
{	
	public:
		float objectAngle(Object obj1);
		void forcesActive(Object& obj1, Collision& collisions, Environment env, sf::RenderWindow& window);
		//this space will be served as a way to make calculations


};

