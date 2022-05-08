#include "Object.h"

	sf::Vector2f Object::size()
	{
		sf::RectangleShape object(this->shape().getPosition().x, this->shape().getPosition().y);
		return sf::Vector2f();
	}

	void Object::weight(float gravity, sf::Vector2f size())
	{
		float totalweight = gravity * this->size();
	}
