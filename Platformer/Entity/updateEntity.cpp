#include "Entity.hpp"

void plt::Entity::update(sf::Vector2f pos)
{
	if (interactComponent != nullptr)
		interactComponent->update(pos);
}