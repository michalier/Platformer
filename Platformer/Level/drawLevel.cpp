#include "Level.hpp"

void plt::Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < elems.size(); i++)
	{
		target.draw(*elems[i], states);
	}

	for (int i = 0; i < hookPoints.size(); i++)
	{
		target.draw(*hookPoints[i], states);
	}
}