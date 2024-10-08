#include "Menu.h"
#include "MenuObserver.h"

namespace Menu {
	Menu::Menu(const ID id, const sf::Vector2f buttonSize, const std::string name, const unsigned int fontSize) :
		State(id), textButtonList(), it(), buttonSize(buttonSize),
		windowSize(sf::Vector2f(pGraphic->getWindowSize().x, pGraphic->getWindowSize().y)),
		title(pGraphic->loadFont("yoster.ttf"), name, fontSize),
		menuObserver(new Observers::MenuObserver(this))
	{
		if (menuObserver == nullptr) {
			std::cout << "ERROR::Menu::MainMenu:: not possible to create observer to main menu" << std::endl;
			exit(1);
		}
	}

	Menu::~Menu() {
		if (!textButtonList.empty()) {
			for (it = textButtonList.begin(); it != textButtonList.end(); it++) {
				delete(*it);
				*it = nullptr;
			}
			textButtonList.clear();
		}
		if (menuObserver) {
			menuObserver->setIsActive(false);
		}
	}

	/*
	void Menu::changeObserverState()
	void Menu::mudarEstadoObservador(){
            observadorMenu->mudarEstadoAtivar();
        }
	*/

	void Menu::addButton(const std::string info, const sf::Vector2f pos, const ID id, const sf::Color selectedColor) {
		Button::TextButton* button = new Button::TextButton(info, pos, buttonSize, id, selectedColor);
		if (button == nullptr) {
			std::cout << "ERROR::Menu:: not possible to create button" << std::endl;
			exit(1);
		}
		textButtonList.push_back(button);
	}

	void Menu::initializeIterator() {
		try {
			it = textButtonList.begin();
			(*it)->setSelected(true);
		} catch (const std::exception& e) 
		{
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}

	void Menu::selectAbove() {
		Button::TextButton* button = *it;
		button->setSelected(false);
		if (it == textButtonList.begin()) {
			it = textButtonList.end();
		}
		it--;
		button = *it;
		button->setSelected(true);
	}

	void Menu::selectBelow() {
		Button::TextButton* button = *it;
		button->setSelected(false);
		it++;
		if (it == textButtonList.end()) {
			it = textButtonList.begin();
		}
		button = *it;
		button->setSelected(true);
	}

	const ID Menu::getSelectedButtonID() const {
		return (*it)->getID();
	}
	void Menu::setIsActive(bool iA) {
		menuObserver->setIsMoreActive(iA);
		pGraphic->centerView(Math::CoordF(windowSize.x / 2.0f, windowSize.y / 2.0f));
		
	}
	bool Menu::getIsActive() {
		return menuObserver->getIsMoreActive();
	}

	void Menu::render() {
		std::list<Button::TextButton*>::iterator aux;
		for (aux = textButtonList.begin(); aux != textButtonList.end(); aux++) {
			Button::TextButton* button = *aux;
			button->render();
			button = nullptr;
		}
	}

}