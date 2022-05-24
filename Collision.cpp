#include "Collision.h"



//void Collision::Object2Object(sf::CircleShape obj1, sf::CircleShape obj2)
//{	// hard, have velocity be attached to an object, and at the angle that it is hitting it at.
//	// try not to import mass into the equation yet, just try velocity -> velocity transfer no outside systesm. 
//	if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) { // if two objects intersect, ( point == point )
//		if
//	}
//}

void Collision::Object2Object(Object obj1, Object obj2)
{
	sf::FloatRect obj1border = obj1.getShape().getGlobalBounds();
	sf::FloatRect obj2border = obj2.getShape().getGlobalBounds();

	if (obj1border.intersects(obj2border)) {
		//if (obj1.getMass() * obj1.getAcceleration() > obj2.getMass() * obj2.getAcceleration()) { //force

		//}
		std::cout << "hrfjdi" << std::endl;
	}

}

void Collision::baseCollision(Object& obj1)
{
	Environment environment;
	sf::RectangleShape base = environment.base();

	float height = base.getPosition().y;
	float objHeight = obj1.getPosition().y;
	float diameter = 2 * obj1.getShape().getRadius();

	if (obj1.getShape().getGlobalBounds().intersects(environment.base().getGlobalBounds())){ // if it dips below the base
		/*sf::Vector2f currentAcc = obj1.getAcceleration();*/
		obj1.setPosition(obj1.getPosition() - _Math::normalize(obj1.getVelocity()));
		//remove this velocity evenntually and change to gravitaional forces
		obj1.setVelocity(sf::Vector2f(obj1.getVelocity().x, -obj1.getVelocity().y));
		obj1.setAcceleration(sf::Vector2f(0, 0.005));
		std::cout << "OGMDMGOFGM" << std::endl;	
	}
}

void Collision::borderCollision(sf::RenderWindow& window, Object& obj1)
{
	float diameter = obj1.getShape().getRadius() * 2;

	if (obj1.getPosition().x + diameter >= window.getSize().x || 0 >= obj1.getPosition().x) {
		obj1.setVelocity(sf::Vector2f(-obj1.getVelocity().x, obj1.getVelocity().y));
	} 
	else if (obj1.getPosition().y + diameter >= window.getSize().y || 0 >= obj1.getPosition().y) {
		obj1.setVelocity(sf::Vector2f(obj1.getVelocity().x, -obj1.getVelocity().y));
	}
}
