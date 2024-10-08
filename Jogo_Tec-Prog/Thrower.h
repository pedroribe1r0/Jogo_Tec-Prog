#pragma once
#include "Zombie.h"

class EntitiesList;
namespace Entities {
	class Projectile;
	namespace Characters {
		#define THROWER_SIZE_X 15.0f
		#define THROWER_SIZE_Y 85.0f
		#define THROWER_HP 90.0f
		#define THROWER_DAMAGE 5.0f
		#define THROWER_SPEED 50.0f
		#define THROWER_ATTACK_TIME 2.85f
		class Thrower : public Enemy
		{
		private:
			Projectile* p;
			bool isAttacking;
			float attackTime;
		public:
			Thrower(Math::CoordF pos = Math::CoordF(0, 0), EntitiesList* list = nullptr);
			~Thrower();
			void damage();
			void update(float dt);
			void takeDistance(Player* p);
			void setTextures();
			string save();
		};
	}
}

