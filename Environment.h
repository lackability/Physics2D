#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Environment
{

	private:
		//unsure if friction should be in the envirnoment stage
		bool frictionState(); // friciton on or off
		float gravity; //gravity described in envirnoment

	public:
		float windspeed(); //returns a value in meters per second
		float floorFriction(); // complicated though process, unsure where it should go. 
		
		sf::RectangleShape base(sf::RenderWindow& window); //sorta like the water underneath a map, the base floor
	

		void setGravity(float newG) {
			gravity = newG;
		}
		
		float getGravity() {
			return gravity;
		}
};

