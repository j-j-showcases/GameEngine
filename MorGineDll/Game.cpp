#include "pch.h"
#include "Game.h"

namespace MorGine {
	Game::Game(int width, int height, std::string title)
	{
		this->_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) {
			this->_data->states.ProcessStateChanges();
			

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
				frameTime = 0.25f;

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= this->fps) {
				this->_data->states.GetActiveState()->HandleInput();
				this->_data->states.GetActiveState()->Update(this->fps);

				accumulator -= this->fps;
			}

			interpolation = accumulator / this->fps;
			this->_data->states.GetActiveState()->Draw(fps);
		}
	}
}