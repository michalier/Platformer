#include "Game.hpp"
#include <iostream>
#include "../Math/Math.hpp"

void plt::Game::handleInput()
{
	bool move_l = sf::Keyboard::isKeyPressed(sf::Keyboard::A),
		move_r = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	
	if (move_l)
	{
		if (player->vector.x > -4)
			player->vector.x -= 1;
		else
			player->vector.x = -5;
	} 
	
	if (move_r)
	{
		if (player->vector.x < 4)
			player->vector.x += 1;
		else
			player->vector.x = 5;
	}
	
	if (!move_l && !move_r)
	{
		if (player->vector.x > 0.5)
			player->vector.x -= 0.5;
		else if (player->vector.x < -0.5)
			player->vector.x += 0.5;
		else
			player->vector.x = 0;
	}
}