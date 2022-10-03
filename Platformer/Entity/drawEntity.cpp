#include "Entity.hpp"

void plt::Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (displayComponent != nullptr)
		target.draw(*displayComponent, states);

	if (interactComponent != nullptr)
		target.draw(*interactComponent, states);
}