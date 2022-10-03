#include "Game.hpp"

void plt::Game::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		window.close();

	switch (state)
	{
	case plt::GameState::GameLevel:
		if (player->getState() == plt::PlayerState::UsingTerminal)
			this->minigameEvent(event);
		else
			this->gameLevelEvent(event);
		break;
	default:
		break;
	}
	
}