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
			//this->setState(GameState::GameLevel);
			this->loadLevel(0);
		});
		gui.add(newGameButton, "bar");

		break;
	}
	case plt::GameState::LoadingLevel:
	{
		auto bar = tgui::ProgressBar::create();
		bar->setMinimum(0);
		bar->setMaximum(100);
		bar->setSize("&.width * 0.5", "&.height * 0.04");
		bar->setPosition("&.width * 0.25", "&.height * 0.46");
		
		gui.add(bar, "bar");
	}
	case plt::GameState::GameLevel:
	{
		this->player->level = this->level;
	}
	default:
		break;
	}
}