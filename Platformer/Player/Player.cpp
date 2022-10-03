#include "Player.hpp"
#include "../Entity/Component/DisplayComponent/DrawFromPointsComponent/DrawFromPointsComponent.hpp"
#include "../Entity/Component/PhysicsComponent/PhysicsComponent.hpp"

plt::Player::Player(sf::Vector2f position, Level* level) : plt::Entity(position)
{
	this->setState(PlayerState::Falling);

	this->level = level;

	displayRange = false;

	this->hookOffset = sf::Vector2f(0, -25);
	this->hookLenght = 650;
	this->hookSpeed = 30;
	this->hookSelected = nullptr;

	hookRange.setPosition(position);
	hookRange.setRadius(hookLenght);
	hookRange.setFillColor(sf::Color::Transparent);
	hookRange.setOutlineThickness(2);
	hookRange.setOutlineColor(sf::Color::Black);
	hookRange.setOrigin(hookLenght, hookLenght);

	hookLine.setSize(sf::Vector2f(4, 0));
	hookLine.setOrigin(2, 0);
	hookLine.setFillColor(sf::Color(200, 200, 200));
	hookLine.setPosition(position + hookOffset);

	this->collisionComponent = new CollisionComponent(&this->position, sf::Vector2f(50, 30));
	
	this->displayComponent = new plt::DrawFromPointsComponent(
		std::bind(&plt::CollisionComponent::getPoints, this->collisionComponent)
	);
	
	this->physicsComponent = new plt::PhysicsComponent();

	this->jumped = false;

	playerView.setSize(sf::Vector2f(1280, 720));
	playerView.setCenter(665, 375);
}

sf::View& plt::Player::getView()
{
	return playerView;
}

plt::Player* plt::Player::summon(sf::Vector2f position, Level* level)
{
	return new Player(position, level);
}