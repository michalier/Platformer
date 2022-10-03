#include "Entity.hpp"
#include <iostream>

plt::Entity::Entity(sf::Vector2f position)
{
	this->position = position;

	this->collisionComponent = nullptr;
	this->displayComponent = nullptr;
	this->interactComponent = nullptr;

	this->vector = sf::Vector2f(0, 0);
}