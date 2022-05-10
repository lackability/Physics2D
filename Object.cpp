#include "Object.h"

	//void Object::weight(float gravity)
	//{
	//	float totalweight = gravity * this->shape;
	//}

float Object::getWeight(float gravity, int mass)
{
	float weight = gravity * mass;
	return weight;
}

float Object::getVelocity()
{
	sf::Mouse::getPosition()
	return 0.0f;
}
