#include "DisplayRect.hpp"

plt::DisplayRect::DisplayRect(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
	rs.setOrigin(size.x / 2, size.y / 2);
	rs.setPosition(pos);
	rs.setSize(size);
	rs.setFillColor(color);
}

void plt::DisplayRect::setColor(sf::Color color)
{
	rs.setFillColor(color);
}

void plt::DisplayRect::update(sf::Vector2f p)
{
}

void plt::DisplayRect::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rs, states);
}