#pragma once
#include "NewGameMenu.h"

namespace Menu {
	class PauseMenu : public Menu {
	private:
		
	public:
		PauseMenu(States::Levels::Level* level = nullptr);
		//PauseMenu(const ID id, std::string name, States::Levels::Level* level = nullptr);
		~PauseMenu();
		void createButtons();
		void setLevel(States::Levels::Level* level);
		States::Levels::Level* getLevel();
		void render();
		void execute(float dt);
		void saveLevel();
	};





}