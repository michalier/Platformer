#include "Game.hpp"
#include <thread>

void plt::Game::loadLevel(int nr)
{
	setState(GameState::LoadingLevel);
	delete level;
	level = new Level();
	std::string name = "level" + std::to_string(nr) + ".txt";

	std::thread t(std::bind(&Level::load, level, &font, name));
	t.detach();
}