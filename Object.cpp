#include "Object.h"

	//void Object::weight(float gravity)
	//{
	//	float totalweight = gravity * this->shape;
	//}

bool Object::select(bool selected)
{
	//can replace with rectangle shape
	float width = 2*this->shape.getRadius();
	float height = 2*this->shape.getRadius();
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	if (selected != true) {
		if ((mousePos.x <= this->shape.getPosition().x + width) && (mousePos.x >= this->shape.getPosition().x)) {
			if ((mousePos.y <= this->shape.getPosition().y + height) && (mousePos.y >= this->shape.getPosition().y)) {
				this->shape.setPosition(mousePos.x - (width / 2), mousePos.y - (height / 2));
				bool selected = true;	// hooked onto mouse
				return false;
			}
		}
	}
	else {
		this->shape.setPosition(mousePos.x - (width / 2), mousePos.y - (height / 2));
		return true;
	}
	
}

float Object::getWeight(float gravity, int mass)
{
	float weight = gravity * mass;
	return weight;
}

float Object::getVelocity(sf::Vector2f displacement)
{
	float velocity = abs(sqrt(pow(displacement.x, 2) + pow(displacement.y, 2))); //pygathorean theorem
	return velocity;
}

float Object::getAccerlation(sf::Vector2f displacement)
{
	return 0.0f;
}

sf::Vector2f Object::getDisplacement(sf::Vector2f initPos)
{
	sf::Vector2f finalPos = this->getShape().getPosition();
	sf::Vector2f displacement = sf::Vector2f((finalPos.x - initPos.x), (finalPos.y - initPos.y));
	return displacement;
}
