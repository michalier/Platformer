#pragma once
#include <SFML/Graphics.hpp>

#include "Component/CollisionComponent/CollisionComponent.hpp"
#include "Component/DisplayComponent/DisplayComponent.hpp"
#include "Component/InteractComponent/InteractComponent.hpp"

namespace plt
{
	class Entity : public sf::Drawable
	{
	protected:
		
	public:
		sf::Vector2f position, vector;
		
		CollisionComponent* collisionComponent;
		DisplayComponent* displayComponent;
		InteractComponent* interactComponent;

		void update(sf::Vector2f pos);

		Entity(sf::Vector2f position);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		static Entity* summonRect(sf::Vector2f position, sf::Vector2f size);
		static Entity* summonCircle(sf::Vector2f position, float radius);
		static Entity* summonInteractable(sf::Vector2f position, sf::Vector2f size, std::string message);
		//static Entity* summonTriangle(sf::Vector2f position, sf::Vector2f p2, sf::Vector2f p3);
	};
}