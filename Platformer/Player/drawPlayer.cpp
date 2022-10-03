#include "Player.hpp"

void plt::Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (hookDuty())
		target.draw(hookLine, states);

	if (displayComponent != nullptr)
		target.draw(*displayComponent, states);

	if (displayRange)
		target.draw(hookRange, states);
}