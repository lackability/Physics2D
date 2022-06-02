#include "Collision.h"

bool Collision::Object2Object(Object& obj1, Object& obj2)
{
	sf::FloatRect obj1border = obj1.getShape().getGlobalBounds();
	sf::FloatRect obj2border = obj2.getShape().getGlobalBounds();

	if (obj1border.intersects(obj2border)) {
		obj1.setVelocity({ -obj1.getVelocity().x, -obj1.getVelocity().y });
		obj1.setPosition(obj1.getPosition() - _Math::normalize(obj1.getPosition()));
		obj2.setVelocity({ -obj1.getVelocity().x, -obj2.getVelocity().y });
		obj2.setPosition(obj2.getPosition() + _Math::normalize(obj2.getPosition()));
		std::cout << "hrfjdi" << std::endl;
	}
	return false;

}

bool Collision::inAir(Object& obj1, Environment& environment, sf::RenderWindow& window)
{
	bool floorC = floorCollision(obj1, environment);
	bool borderC = borderCollision(window, obj1);

	if (floorC && borderC == false) {
		return true;
	}
	else if (floorC || borderC) {
		return false;
	}
}

bool Collision::floorCollision(Object& obj1, Environment& environment)
{
	sf::RectangleShape base = environment.base();

	float height = base.getPosition().y;
	float objHeight = obj1.getPosition().y;
	sf::Vector2f objPos = obj1.getPosition();
	float diameter = 2 * obj1.getShape().getRadius();

	if (obj1.getShape().getGlobalBounds().intersects(environment.base().getGlobalBounds())){ // if it dips below the base
		obj1.setPosition(objPos - _Math::normalize(objPos));

		//remove this velocity evenntually and change to gravitaional forces
		obj1.setVelocity(sf::Vector2f(obj1.getVelocity().x, -obj1.getVelocity().y * 0.94));
		//0.94 IS BOUNCE percentage back
		obj1.setAcceleration(sf::Vector2f(0, environment.getGravity()));
		return true;
	}
	return false;
}

bool Collision::borderCollision(sf::RenderWindow& window, Object& obj1)
{
	float diameter = obj1.getShape().getRadius() * 2;

	if (obj1.getPosition().x + diameter >= window.getSize().x || 0 >= obj1.getPosition().x) {
		obj1.setVelocity(sf::Vector2f(-obj1.getVelocity().x, obj1.getVelocity().y));
		return true;
	} 
	else if (obj1.getPosition().y + diameter >= window.getSize().y || 0 >= obj1.getPosition().y) {
		obj1.setVelocity(sf::Vector2f(obj1.getVelocity().x, -obj1.getVelocity().y));
		return true;
	}
	return false;
}
