#include "InputManager.h"

namespace Managers{
	InputManager* InputManager::pInput = nullptr;

	InputManager* InputManager::getInstance() {
		if (!pInput)
			pInput = new InputManager();
		return pInput;
	}

	InputManager::InputManager() : observers(){

	}

	InputManager::~InputManager() {
		observers.clear();
	}

	void InputManager::handleKeyPressed(sf::Keyboard::Key key) {
		std::list<Observers::Observer*>::iterator it;
		for (it = observers.begin(); it != observers.end(); it++) {
			(*it)->notifyKeyPressed(key);
		}
	}
	void InputManager::handleKeyReleased(sf::Keyboard::Key key) {
		std::list<Observers::Observer*>::iterator it;
		for (it = observers.begin(); it != observers.end(); it++) {
			(*it)->notifyKeyReleased(key);
		}
	}
	void InputManager::addObserver(Observers::Observer* obs) {
		if (obs) {
			observers.push_back(obs);
			return;
		}
		std::cout << "Error! obs is nullptr" << endl;
	}
	void InputManager::removeObserver(Observers::Observer* obs) {
		if (obs) {
			observers.remove(obs);
			return;
		}
		std::cout << "Error! obs is nullptr" << endl;
	}
}