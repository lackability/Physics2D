#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
class Object
{
	private:
		sf::RectangleShape shape(); //stick to rectangle for testing 
		bool breakable();
		bool groundstateMovability(); //can it move from resistence from ground vs force extered? 

	public:
		float mass(); //in terms of grams or kilograms
		float weight(float gravity); 
		float velocity(); //simple
		float accerlation();

};

