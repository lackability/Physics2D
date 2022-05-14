#include "Object.h"

bool Object::select(bool selected)
{
	//can replace with rectangle shape
	float width = 2*this->shape.getRadius();
	float height = 2*this->shape.getRadius();
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	this->shape.setPosition(mousePos.x - (width / 2), mousePos.y - (height / 2));
	return false;
}

float Object::getWeight(float gravity, int mass) //returns weight in newtons/unit
{
	float weight = gravity * mass;
	return weight;
}

float Object::getVelocity(sf::Vector2f displacement) 
{
	float velocity = abs(sqrt(displacement.x*displacement.x + displacement.y* displacement.y)); //pygathorean theorem
	return velocity;
}

float Object::getAcceleration(float initVelocity, float finalVelocity)
{
	float acceleration = finalVelocity - initVelocity;
	return acceleration;
}

sf::Vector2f Object::getDisplacement(sf::Vector2f initPos) //displacement in units
{
	sf::Vector2f finalPos = this->getShape().getPosition();
	sf::Vector2f displacement = sf::Vector2f((finalPos.x - initPos.x), (finalPos.y - initPos.y));
	return displacement;
}
