#include "Entity.hpp"
#include "Component/DisplayComponent/DrawFromPointsComponent/DrawFromPointsComponent.hpp"
#include "Component/DisplayComponent/DisplayCircle/DisplayCircle.hpp"
#include "Component/DisplayComponent/DisplayRect/DisplayRect.hpp"

plt::Entity* plt::Entity::summonRect(sf::Vector2f position, sf::Vector2f size)
{
	Entity* e = new Entity(position);

	e->collisionComponent = new CollisionComponent(&e->position, size);

	e->displayComponent = new DrawFromPointsComponent(
		std::bind(&CollisionComponent::getPoints, e->collisionComponent), 
		sf::Color::Green
	);

	return e;
}

plt::Entity* plt::Entity::summonCircle(sf::Vector2f position, float radius)
{
	Entity* e = new Entity(position);

	e->displayComponent = new DisplayCircle(position, radius, sf::Color::Black);

	return e;
}

plt::Entity* plt::Entity::summonInteractable(sf::Vector2f position, sf::Vector2f size, std::string message)
{
	Entity* e = new Entity(position);

	e->displayComponent = new DisplayRect(position, size, sf::Color::Blue);

	e->interactComponent = new InteractComponent(position, message, size.x);

	return e;
}