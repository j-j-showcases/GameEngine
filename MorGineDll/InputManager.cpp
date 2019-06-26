#include "pch.h"
#include "InputManager.h"

namespace MorGine {
	bool InputManager::SpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, const sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect spriteRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

			if (spriteRect.contains(sf::Mouse::getPosition()))
				return true;
		}

		return false;
	}
	sf::Vector2i InputManager::GetMousePosition(const sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}
}
