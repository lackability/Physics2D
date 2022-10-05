#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Environment.h"

class Object
{
	private:
		Environment* environment;
		sf::CircleShape shape; // circle shape can make triangles, any other geometrical standard shape
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f acceleration; 
		float weight;
		bool selected;
		bool breakable;
		float mass; //in terms of grams or kilograms

	public:
		static std::vector<Object*> list;
		Object(Environment* environment);

		void update();
		bool select(bool selected); // select operation, returns isSelected t/f

		sf::CircleShape getShape();
		sf::Vector2f getPosition();
		sf::Vector2f getVelocity();
		sf::Vector2f getAcceleration();
		float getWeight();
		bool getSelected();
		bool getBreakable();
		int getMass();

		void setShape(sf::CircleShape newshape);
		void setPosition(sf::Vector2f position);
		void setVelocity(sf::Vector2f velocity);
		void setAcceleration(sf::Vector2f acceleration);
		void setSelected(bool Nselected);
		void setBreakable(bool status);
		void setMass(float grams);

};

