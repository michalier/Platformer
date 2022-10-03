#pragma once
#include "../DisplayComponent.hpp"

namespace plt
{
	class DisplayRect : public plt::DisplayComponent
	{
	protected:
		sf::RectangleShape rs;

	public:
		DisplayRect(sf::Vector2f pos, sf::Vector2f size, sf::Color color);

		virtual void setColor(sf::Color color);
		virtual void update(sf::Vector2f p);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};
}
