#pragma once
#include "Enemy.h"

namespace Entities {
	namespace Characters {
		class Animation;
		#define ZOMBIE_SIZE_X 15.0f
		#define ZOMBIE_SIZE_Y 85.0f
		#define ZOMBIE_HP 100.0f
		#define ZOMBIE_DAMAGE 20.0f
		#define ZOMBIE_SPEED 60.0f
		class Zombie : public Enemy
		{
		private:
			float zombieSpeed;
		public:
			Zombie(Math::CoordF pos = Math::CoordF(0, 0));
			~Zombie();
			void damage();
			void update(float dt);
			void setTextures();
			void increaseSpeed(float speed);
			string save();
		};
	}
}

