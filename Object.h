#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
class Object
{
	public:
		sf::RectangleShape shape();
		sf::Vector2f size();
		void weight(float gravity, sf::Vector2f size(sf::Vector2f dimensions(int x, int y)));
};

