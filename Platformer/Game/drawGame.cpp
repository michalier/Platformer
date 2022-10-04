#include "Game.hpp"

void plt::Game::drawGame()
{
	window.clear(sf::Color::White);

	if (state == GameState::GameLevel)
	{
		window.setView(player->getView());

		window.draw(*level);
		window.draw(*player);

		window.setView(window.getDefaultView());

		window.draw(debugText);
	}

	gui.draw();

	window.display();
}