#include "Object.h"

	//void Object::weight(float gravity)
	//{
	//	float totalweight = gravity * this->shape;
	//}

bool Object::select()
{
	float width = this->shape.getRadius();
	float height = this->shape.getRadius();
	
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	if (mousePos.x <= mousePos.x + width && mousePos.x >= mousePos.x - width) {
		if (mousePos.y <= mousePos.y + height && mousePos.y >= mousePos.y - height) {
			this->shape.setPosition(mousePos.x, mousePos.y);
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

//float Object::getAccerlation()
//{
//	if (this->isSelected) {
//		float initX = sf::Mouse::getPosition().x;
//		float initY = sf::Mouse::getPosition().y;
//
//	}
//	
//	
//	if ()
//	return 0.0f;
//}
