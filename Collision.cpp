#include "Collision.h"

void Collision::Object2Object(sf::CircleShape obj1, sf::CircleShape obj2)
{	// hard, have velocity be attached to an object, and at the angle that it is hitting it at.
	// try not to import mass into the equation yet, just try velocity -> velocity transfer no outside systesm. 
	if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) { // if two objects intersect, ( point == point )
		if
	}
}
