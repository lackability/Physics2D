#pragma once
class Environment
{
	class Weather {
		public:
			//descriptions of weather, rain will cause friction slip, etc...
			void rain();
			void snow();
			void clear();
	};

	private:
		//unsure if friction should be in the envirnoment stage
		bool frictionState(); // friciton on or off

	public:
		float gravity(); //gravity described in envirnoment
		float windspeed(); //returns a value in meters per second
		float floorFriction(); // complicated though process, unsure where it should go. 
			
};

