#include "Level.hpp"

void plt::Level::load(sf::Font& font)
{
	this->space.left = 0;
	this->space.top = 0;
	this->space.width = 2560;
	this->space.height = 1440;

	this->elems.push_back(Entity::summonRect(sf::Vector2f(1280, 15), sf::Vector2f(2560, 30)));
	this->elems.push_back(Entity::summonRect(sf::Vector2f(1280, 1425), sf::Vector2f(2560, 30)));
	this->elems.push_back(Entity::summonRect(sf::Vector2f(15, 720), sf::Vector2f(30, 1440)));
	this->elems.push_back(Entity::summonRect(sf::Vector2f(2545, 720), sf::Vector2f(30, 1440)));
	
	this->elems.push_back(Entity::summonRect(sf::Vector2f(250, 390), sf::Vector2f(500, 30)));
	this->elems.push_back(Entity::summonRect(sf::Vector2f(1150, 390), sf::Vector2f(500, 30)));

	Entity* e = Entity::summonInteractable(sf::Vector2f(200, 350), sf::Vector2f(30, 50), "test1");
	sf::Text* t = new sf::Text("Press E", font, 20);
	t->setPosition(200 - t->getGlobalBounds().width / 2, 305);
	t->setOutlineThickness(2);
	t->setOutlineColor(sf::Color::Black);
	e->interactComponent->popup = t;
	this->elems.push_back(e);

	this->hookPoints.push_back(Entity::summonCircle(sf::Vector2f(450, 40), 10));
	this->hookPoints.push_back(Entity::summonCircle(sf::Vector2f(950, 40), 10));
}

void plt::Level::update(sf::Vector2f pos)
{
	for (Entity* e : elems)
	{
		e->update(pos);
	}
}