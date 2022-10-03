#include "DisplayCircle.hpp"

plt::DisplayCircle::DisplayCircle(sf::Vector2f pos, float radius, sf::Color color)
{
	cs.setOrigin(radius, radius);
	cs.setPosition(pos);
	cs.setRadius(radius);
	cs.setFillColor(color);
}

void plt::DisplayCircle::setColor(sf::Color color)
{
	cs.setFillColor(color);
}

void plt::DisplayCircle::update(sf::Vector2f p)
{
	cs.setPosition(p);
}

void plt::DisplayCircle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(cs, states);
}
