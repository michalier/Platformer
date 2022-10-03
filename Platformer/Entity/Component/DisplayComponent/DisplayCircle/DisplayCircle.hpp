#pragma once
#include "../DisplayComponent.hpp"

namespace plt
{
	class DisplayCircle : public DisplayComponent
	{
	protected:
		sf::CircleShape cs;

	public:
		DisplayCircle(sf::Vector2f pos, float radius, sf::Color color);
		virtual void setColor(sf::Color color);
		virtual void update(sf::Vector2f p);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
