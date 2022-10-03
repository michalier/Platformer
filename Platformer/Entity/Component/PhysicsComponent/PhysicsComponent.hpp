#pragma once
#include <SFML/Graphics.hpp>

namespace plt
{
	class PhysicsComponent
	{
	protected:

	public:
		sf::Vector2f getVector() { return sf::Vector2f(0, 0.5); }
	};
}