#pragma once
#include "SFML/Graphics.hpp"
#include "../CollisionComponent/CollisionComponent.hpp"
#include <vector>
#include <functional>

namespace plt
{
	using getPointsFunction = std::function<std::vector<sf::Vector2f>* (void)>;

	class DisplayComponent : public sf::Drawable
	{
	public:
		DisplayComponent() { };
		virtual void setColor(sf::Color color) = 0;
		virtual void update(sf::Vector2f p) = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	};
}