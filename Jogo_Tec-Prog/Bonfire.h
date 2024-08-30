#pragma once
#include "Jumper.h"

namespace Entities {
	namespace Obstacles {
		#define BONFIRE_SIZE_X 50.0f
		#define BONFIRE_SIZE_Y 50.0f
		#define BONFIRE_DAMAGE 10.0f
		class Bonfire : public Obstacle
		{
		private:
			float healRatio;
			bool isHealing1;
			bool isHealing2;
			static Entities::Characters::Player* p1;
			static Entities::Characters::Player* p2;
		public:
			Bonfire(Math::CoordF pos = Math::CoordF(0, 0));
			~Bonfire();
			void setTextures();
			void update(float dt);
			void execute(float dt);
			void block(Characters::Player* ent, float dt);
			static void setPlayers(Entities::Characters::Player* pP1 = nullptr, Entities::Characters::Player* pP2 = nullptr);
		};
	}
}

