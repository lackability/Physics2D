#include "Environment.h"
Environment::Environment()
{
	this->gravity = 9.8 / 60;
}

float Environment::windspeed()
{
	return 0.0f;
}

sf::RectangleShape Environment::base()
{
	int width = 1920;
	int height = 80;
	sf::RectangleShape floor;

	floor.setSize(sf::Vector2f(width, height));
	floor.setPosition(0, 720);
	//should be the lowest point of the window
	return floor;
}

void Environment::setGravity(float newG)
{
	gravity = newG;
}

float Environment::getGravity()
{
	return gravity;
}

void Environment::setfrictionState(bool state)
{
	frictionState = state;
}

bool Environment::getfrictionState()
{
	return frictionState;
}

