#pragma once
#include "../DisplayComponent.hpp"
#include <functional>

namespace plt
{
	class DrawFromPointsComponent : public DisplayComponent
	{
	protected:
		sf::VertexArray va;
		getPointsFunction func;

	public:
		DrawFromPointsComponent(getPointsFunction func, sf::Color color = sf::Color::Red);
		virtual void setColor(sf::Color color);
		virtual void update(sf::Vector2f p);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
