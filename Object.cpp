#include "Object.h"

	//void Object::weight(float gravity)
	//{
	//	float totalweight = gravity * this->shape;
	//}

bool Object::select()
{
	//can replace with rectangle shape
	float width = 2*this->shape.getRadius();
	float height = 2*this->shape.getRadius();
	
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	if ((mousePos.x <= this->shape.getPosition().x + width) && (mousePos.x >= this->shape.getPosition().x)) {
		if ((mousePos.y <= this->shape.getPosition().y + height) && (mousePos.y >= this->shape.getPosition().y)) {
			this->shape.setPosition(mousePos.x-(width/2), mousePos.y-(height/2));
			return true; //isselected
		}
	}

	return false;
}

float Object::getWeight(float gravity, int mass)
{
	float weight = gravity * mass;
	return weight;
}

float Object::getVelocity()
{

	return 0.0f;
}

float Object::getAccerlation()
{
	if (this->select()) {
		float initX = sf::Mouse::getPosition().x;
		float initY = sf::Mouse::getPosition().y;

	}


	return 0.0f;
}
