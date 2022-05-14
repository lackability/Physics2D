#pragma once

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Object
{
	private:
		sf::CircleShape shape; // circle shape can make triangles, any other geometrical standard shape
		bool breakable; 
		int mass; //in terms of grams or kilograms


	public:
		float getWeight(float gravity, int mass); 
		float getVelocity(sf::Vector2f displacement); //simple
		float getAcceleration(float initVelocity, float finalVelocity);
		sf::Vector2f getDisplacement(sf::Vector2f initPos);

		bool select(bool selected); // select operation, returns isSelected t/f

		sf::CircleShape getShape() {
			return shape;
		}

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

		void setShape(sf::CircleShape newshape) {
			shape = newshape;
		}
		
		
};

