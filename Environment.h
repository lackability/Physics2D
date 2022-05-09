#pragma once
class Environment
{

	private:
		//unsure if friction should be in the envirnoment stage
		bool frictionState(); // friciton on or off

	public:
		float gravity(); //gravity described in envirnoment
		float windspeed(); //returns a value in meters per second
		float floorFriction(); // complicated though process, unsure where it should go. 
			
};

