#include "pch.h"
#include "AssetManager.h"

namespace MorGine {
	void AssetManager::LoadTexture(std::string name, std::string filePath)
	{
		sf::Texture tempTexture;

		if (tempTexture.loadFromFile(filePath))
			this->_textures[name] = tempTexture;
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string filePath)
	{
		sf::Font tempFont;

		if (tempFont.loadFromFile(filePath))
			this->_fonts[name] = tempFont;
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}
