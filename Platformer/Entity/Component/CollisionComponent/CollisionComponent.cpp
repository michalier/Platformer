#include "CollisionComponent.hpp"

plt::CollisionComponent::CollisionComponent(sf::Vector2f* pos, sf::Vector2f size)
{
	this->position = pos;
	this->size = size;
}

bool plt::CollisionComponent::collides(CollisionComponent* cmp)
{
	sf::Vector2f p1 = sf::Vector2f(position->x - size.x / 2, position->y - size.y / 2),
				p2 = sf::Vector2f(cmp->position->x - cmp->size.x / 2, cmp->position->y - cmp->size.y / 2);
	
	return 
		getLeft() <= cmp->getRight() &&
		getRight() >= cmp->getLeft() &&
		getTop() <= cmp->getBottom() &&
		getBottom() >= cmp->getTop();
}

float plt::CollisionComponent::getLeft() const
{
	return position->x - size.x / 2;
}

float plt::CollisionComponent::getRight() const
{
	return position->x + size.x / 2;
}

float plt::CollisionComponent::getTop() const
{
	return position->y - size.y / 2;
}

float plt::CollisionComponent::getBottom() const
{
	return position->y + size.y / 2;
}

std::vector<sf::Vector2f>* plt::CollisionComponent::getPoints()
{
	std::vector<sf::Vector2f>* v = new std::vector<sf::Vector2f>();

	v->push_back(sf::Vector2f(position->x - size.x / 2, position->y - size.y / 2));
	v->push_back(sf::Vector2f(position->x + size.x / 2, position->y - size.y / 2));
	v->push_back(sf::Vector2f(position->x - size.x / 2, position->y + size.y / 2));
	v->push_back(sf::Vector2f(position->x + size.x / 2, position->y + size.y / 2));

	return v;
}