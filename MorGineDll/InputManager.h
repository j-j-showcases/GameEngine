#pragma once
#include <string>

#include <SFML/Graphics.hpp>

namespace MorGine {
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}
		bool SpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, const sf::RenderWindow& window);

		sf::Vector2i GetMousePosition(const sf::RenderWindow& window);
	private:
	};
}

