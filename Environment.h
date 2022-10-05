#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Environment
{
	private:
		float gravity; //gravity described in envirnoment

		

	public:
		Environment();

		float windspeed(); //returns a value in meters per second
		sf::RectangleShape base(); //sorta like the water underneath a map, the base floor

		float getGravity();
		void setGravity(float newG);


};

