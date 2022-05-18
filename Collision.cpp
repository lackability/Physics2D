#include "Collision.h"


//void Collision::Object2Object(sf::CircleShape obj1, sf::CircleShape obj2)
//{	// hard, have velocity be attached to an object, and at the angle that it is hitting it at.
//	// try not to import mass into the equation yet, just try velocity -> velocity transfer no outside systesm. 
//	if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) { // if two objects intersect, ( point == point )
//		if
//	}
//}

void Collision::Object2Object(sf::CircleShape obj1, sf::CircleShape obj2)
{
	sf::FloatRect obj1border = obj1.getGlobalBounds();
	sf::FloatRect obj2border = obj2.getGlobalBounds();

	if (obj1border.intersects(obj2border)) {
		std::cout << "hrfjdi" << std::endl;
	}

}

void Collision::baseCollision(sf::CircleShape obj1, sf::RectangleShape base)
{
	float height = base.getPosition().y;
	float objHeight = obj1.getPosition().y;
	float diameter = 2 * obj1.getRadius();

	if (height <= objHeight + diameter){ // if it dips below the base
		obj1.setPosition(400, 920);
		std::cout << "OGMDMGOFGM" << std::endl;	
	}
}
