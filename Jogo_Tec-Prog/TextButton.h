#pragma once
#include "Text.h"

namespace Menu {
	namespace Button {

		class TextButton : public Button
		{
		protected:
			bool selected;
			sf::Color selectedColor;
			Text text;

			const sf::Vector2f getTextSize() const;
		public:
			TextButton(const std::string info, const sf::Vector2f pos, const sf::Vector2f size, const buttonID id, const sf::Color selectedColor);
			virtual ~TextButton();
			//void updateAnimation();
			//void updateBoxPosition(const sf::Vector2f pos);
			void setSelected(bool selected);
			const bool getSelected() const;
			virtual void render();
		};
	}
}