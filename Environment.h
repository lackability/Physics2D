#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Environment
{
	private:
		float gravity; //gravity described in envirnoment

		//unsure if friction should be in the envirnoment stage
		bool frictionState; // friciton on or off
		

	public:
		float windspeed(); //returns a value in meters per second
		float floorFriction(); // complicated though process, unsure where it should go. 
		sf::RectangleShape base(); //sorta like the water underneath a map, the base floor

		float getGravity();
		bool getfrictionState();

		void setGravity(float newG);
		void setfrictionState(bool state);


};

