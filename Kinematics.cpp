#include "Kinematics.h"

float Kinematics::objectAngle(Object obj1)
{
	float yVel = obj1.getVelocity().y; // postivie down, negative up
	float xVel = obj1.getVelocity().x; // positive right, negative left

	float angularDirection = atan(yVel / xVel) * (180/3.14); // will return quad 1 

	if (angularDirection < 0) {
		if (yVel < 0 && xVel > 0) {
			angularDirection = abs(angularDirection); // quad 1
		}
		if (yVel > 0 && xVel < 0) { // if quad 3 
			angularDirection = abs(angularDirection - 180);
		}
	}

	if (angularDirection > 0) { 
		if (yVel > 0 && xVel > 0) { // quad 4
			angularDirection = abs(angularDirection - 360);
		}
		if (yVel < 0 && xVel < 0) { // quad 2
			angularDirection = abs(angularDirection - 180);
		}

		std::cout << angularDirection << std::endl;
	}
	return angularDirection;
}

void Kinematics::forcesActive(Object& obj1, Collision& collisions, Environment env, sf::RenderWindow& window)
{
	//OBJ ANGLE should be calculate upon when it his an object, where it is a ramp
	/*float objAngle = objectAngle(obj1);*/

	//collisions
	collisions.inAir(obj1, env, window);
	collisions.floorCollision(obj1, env);
	collisions.borderCollision(window, obj1);

	//gravity
	float gravityF = env.getGravity() * obj1.getMass() * cos(90);

		
	//normal force
	// why does this condition need to be met to be bounced on the side of hte windows?
	// I.E. test with this conditional commented. 
	if (collisions.inAir(obj1, env, window)) {
		float normalF = 0;
	}
	else {
		float normalF = obj1.getMass() * env.getGravity() * cos(90);
	}
	
	
	//applied force
	float appliedFx = (obj1.getMass() * obj1.getAcceleration().x);
	float appliedFy = (obj1.getMass() * obj1.getAcceleration().y);
	float appliedFtot = sqrt(appliedFx * appliedFx + appliedFy * appliedFy);

	/*float allF = gravityF +  + appliedFtot;*/ //gravity is negative since it needs to pull down

	/*std::cout << allF << std::endl;*/

}

