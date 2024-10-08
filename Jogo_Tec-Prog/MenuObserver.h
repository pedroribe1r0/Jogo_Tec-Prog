#pragma once
#include "GameOverMenu.h"
//Codigo baseado no Matheus Augusto Burda(Burda Canal no Youtube)

namespace State {
	class StateMachine;
}

namespace Observers {
	class MenuObserver : public Observer {
	private:
		Menu::Menu* menu;
		sf::Keyboard::Key select;
		sf::Keyboard::Key up;
		sf::Keyboard::Key down;
		sf::Keyboard::Key right;
		sf::Keyboard::Key left;
		sf::Keyboard::Key esc;

	public:
		MenuObserver(Menu::Menu* menu);
		~MenuObserver();
		void notifyKeyPressed(const sf::Keyboard::Key key);
		void notifyKeyReleased(const sf::Keyboard::Key key);
		std::string keyToString(sf::Keyboard::Key key);
		//void moveMouse(const sf::Vector2f mousePos);
		//void notifyMouseButtonReleased(const sf::Mouse::Button mouseButton);
	};
}