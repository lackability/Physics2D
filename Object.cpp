#include "Object.h"

bool Object::select(bool selected)
{
	//can replace with rectangle shape
	float width = 2*this->shape.getRadius();
	float height = 2*this->shape.getRadius();
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	if (selected) {		// skips hitbox checker, as object has "hooked" onto mouse
		this->shape.setPosition(mousePos.x - (width / 2), mousePos.y - (height / 2));
		return true;
	} 
	else {		//checks if selected false, if false, get position based on hitbox, then returns selected true
		if ((mousePos.x <= this->shape.getPosition().x + width) && (mousePos.x >= this->shape.getPosition().x)) {		//hitbox checker
			if ((mousePos.y <= this->shape.getPosition().y + height) && (mousePos.y >= this->shape.getPosition().y)) {
				this->shape.setPosition(mousePos.x - (width / 2), mousePos.y - (height / 2));
				bool selected = true;	// hooked onto mouse
				return false;
			}
		}
	}
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

float Object::getAccerlation(sf::Vector2f displacement)
{
	return 0.0f;
}

sf::Vector2f Object::getDisplacement(sf::Vector2f initPos) //displacement in units
{
	sf::Vector2f finalPos = this->getShape().getPosition();
	sf::Vector2f displacement = sf::Vector2f((finalPos.x - initPos.x), (finalPos.y - initPos.y));
	return displacement;
}
