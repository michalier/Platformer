#include "Game.hpp"

void plt::Game::setState(GameState state)
{
	this->state = state;
	gui.removeAllWidgets();

	switch (state)
	{
	case plt::GameState::MainMenu:
	{
		window.create(sf::VideoMode(1280, 720), "Platformer");
		window.setFramerateLimit(60);

		auto newGameButton = tgui::Button::create("New Game");
		newGameButton->setSize(144, 36);
		newGameButton->setPosition("&.width * 0.75", "&.height * 0.2");
		newGameButton->onClick([&]() {
			this->setState(GameState::GameLevel);
		});
		gui.add(newGameButton);

		break;
	}
	default:
		break;
	}
}