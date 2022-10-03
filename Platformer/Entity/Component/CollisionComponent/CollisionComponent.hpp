#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../../../Math/Line.hpp"

namespace plt
{
	class CollisionComponent
	{
	protected:
		sf::Vector2f* position;
		sf::Vector2f size;

	public:
		CollisionComponent(sf::Vector2f* pos, sf::Vector2f size);

		bool collides(CollisionComponent* cmp);

		float getLeft() const;
		float getRight() const;
		float getTop() const;
		float getBottom() const;

		std::vector<sf::Vector2f>* getPoints();
	};
}
