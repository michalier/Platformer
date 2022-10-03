#include "Player.hpp"

void plt::Player::move(sf::Vector2f vec)
{
	this->position += vec;
	this->hookRange.move(vec);
	this->hookLine.move(vec);

	sf::Vector2f p(0, 0);
	if (this->position.x >= level->space.left + 640 && this->position.x <= level->space.left + level->space.width - 640)
		p.x = position.x;
	else if (this->position.x < level->space.left + 640)
		p.x = level->space.left + 640;
	else
		p.x = level->space.left + level->space.width - 640;

	if (this->position.y >= level->space.top + 360 && this->position.y <= level->space.top + level->space.height - 360)
		p.y = position.y;
	else if (this->position.y < level->space.top + 360)
		p.y = level->space.top + 360;
	else
		p.y = level->space.top + level->space.height - 360;

	playerView.setCenter(p);
}