#include "Game.hpp"

plt::Game::Game()
{
	window.create(sf::VideoMode(1280, 720), "Platformer");
	window.setFramerateLimit(60);

	this->font.loadFromFile("C:/Windows/Fonts/georgia.ttf");

	this->debugText.setFillColor(sf::Color::White);
	this->debugText.setOutlineThickness(1);
	this->debugText.setOutlineColor(sf::Color::Black);
	this->debugText.setCharacterSize(18);
	this->debugText.setFont(this->font);

	//this->loadLevel(0);

	this->player = Player::summon(sf::Vector2f(100, 100));

	this->gui.setTarget(window);

	this->draggedWidget = nullptr;
	this->widgetOffset = sf::Vector2f(0, 0);

	this->setState(GameState::MainMenu);
}