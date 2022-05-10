#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Object
{
	private:
		sf::RectangleShape shape; //stick to rectangle for testing 
		bool breakable; 
		int mass; //in terms of grams or kilograms
		bool groundstateMovability(); //can it move from resistence from ground vs force extered? 


	public:
		float getWeight(float gravity, int mass); 
		float getVelocity(); //simple
		float getAccerlation();

		int getMass() {
			return mass;
		};
		
		void setMass(int grams) {
			mass = grams;
		};

		bool getBreakable() {
			return breakable;
		};

		void setBreakable(bool status) {
			breakable = status;
		};

};

