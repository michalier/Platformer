#include "Game.hpp"

void plt::Game::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			gui.handleEvent(event);
			this->handleEvent(event);
		}

		if (state == GameState::LoadingLevel && level != nullptr)
		{
			auto b = gui.get<tgui::ProgressBar>("bar");
			b->setValue(level->progress);

			if (level->progress == 100)
				this->setState(GameState::GameLevel);
		}

		if (state == GameState::GameLevel)
		{
			this->handleInput();

			if (player->getState() == PlayerState::UsingTerminal)
			{
				gui.get<Minigame>("terminalWindow")->update();
			}
			else
			{
				player->updatePlayer();

				level->update(player->position);
			}

			this->debugText.setString(
				"mouse: " + std::to_string(sf::Mouse::getPosition().x - window.getPosition().x - 8) + " " + std::to_string(sf::Mouse::getPosition().y - window.getPosition().y - 38) + "\n" +
				"position: " + std::to_string(player->position.x) + " " + std::to_string(player->position.y) + "\n" +
				player->stateToString()
			);
		}

		this->drawGame();
	}
}