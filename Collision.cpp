#include "Collision.h"
#include "Object.h"

//void Collision::Object2Object(sf::CircleShape obj1, sf::CircleShape obj2)
//{	// hard, have velocity be attached to an object, and at the angle that it is hitting it at.
//	// try not to import mass into the equation yet, just try velocity -> velocity transfer no outside systesm. 
//	if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) { // if two objects intersect, ( point == point )
//		if
//	}
//}

void Collision::baseCollision(sf::CircleShape obj1, sf::RectangleShape base)
{
	float height = base.getPosition().y;
	float objPos = (obj1.getPosition().y);

	if (base.getGlobalBounds().contains(obj1.getPosition().x, obj1.getPosition().y + (0, 2*obj1.getRadius()))){ // if it dips below the base
		obj1.setPosition(obj1.getPosition().x, height - (2*obj1.getRadius()));
	}
}
