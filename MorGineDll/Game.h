#pragma once
#include "StateManager.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace MorGine {
	struct GameData {
		StateManager states;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager inputs;
	};
	typedef std::shared_ptr<GameData> gameDataRef;
	class Game
	{
	public:
		Game(int width, int height, std::string title);
		~Game() {}
	private:

		const float fps = 1.0f / 60.0f;
		sf::Clock _clock;

		gameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}

