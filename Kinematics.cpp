#include "Kinematics.h"

void Kinematics::forcesActive(Object& obj1, Environment env)
{
	float angularDirection = atan(obj1.getVelocity().y / obj1.getVelocity().x) * (180/3.14);
	std::cout << angularDirection << std::endl;

	//gravity
	float gravityF = env.getGravity() * obj1.getMass();

		
	//normal force
	float normalF = obj1.getMass() * env.getGravity();
	
	//applied force
	float appliedFx = (obj1.getMass() * obj1.getAcceleration().x);
	float appliedFy = (obj1.getMass() * obj1.getAcceleration().y);
	float appliedFtot = sqrt(appliedFx * appliedFx + appliedFy * appliedFy);

	/*std::cout << appliedFtot << std::endl;*/

}
