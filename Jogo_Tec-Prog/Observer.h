#pragma once
#include "CollisionManager.h"
//Codigo baseado no Matheus Augusto Burda(Burda Canal no Youtube)

namespace Managers {
	class InputManager;
}
namespace States {
	class StateMachine;
}
namespace Observers {
	class Observer {
	protected:
		Managers::InputManager* pInput;
		bool isDeleting;
		bool isActive;
		bool canPress;
		States::StateMachine* pMachine;
	public:
		Observer();
		virtual ~Observer();

		virtual void notifyKeyPressed(sf::Keyboard::Key key) = 0;
		virtual void notifyKeyReleased(sf::Keyboard::Key key) = 0;
		void setIsActive(bool iA);
		bool getIsActive();
		void setIsMoreActive(bool isMA);
		bool getIsMoreActive();
		bool getCanPress();
		void setCanPress(bool cP);
	};
}

