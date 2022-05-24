#include "Object.h"

Object::Object(Environment* environment)
{
	list.push_back(this);
	this->environment = environment;
	this->selected = false;
	this->breakable = false;
	this->mass = 0;
	this->weight = 0;
}

bool Object::select(bool selected)
{
	//can replace with rectangle shape
	float width = 2*this->shape.getRadius();
	float height = 2*this->shape.getRadius();
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	this->shape.setPosition(mousePos.x - (width / 2), mousePos.y - (height / 2));
	return false;
}


void Object::update()
{
	velocity += acceleration;
	position += velocity;
	shape.setPosition(position);
}

sf::CircleShape Object::getShape()
{
	return shape;
}

sf::Vector2f Object::getPosition()
{
	return this->position;
}

sf::Vector2f Object::getVelocity()
{
	return this->velocity;
}

sf::Vector2f Object::getAcceleration()
{
	return this->acceleration;
}

float Object::getWeight()
{
	weight = mass * environment->getGravity();
	return weight;
}

void Object::setShape(sf::CircleShape newshape)
{
	shape = newshape;
}

void Object::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->shape.setPosition(position);
}

void Object::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

void Object::setAcceleration(sf::Vector2f acceleration)
{
	this->acceleration = acceleration;
}

int Object::getMass()
{
	return mass;
}

void Object::setMass(float grams)
{
	mass = grams;
}

bool Object::getBreakable()
{
	return breakable;
}

void Object::setBreakable(bool status)
{
	breakable = status;
}

bool Object::getSelected()
{
	return selected;
}

void Object::setSelected(bool Nselected)
{
	selected = Nselected;
}