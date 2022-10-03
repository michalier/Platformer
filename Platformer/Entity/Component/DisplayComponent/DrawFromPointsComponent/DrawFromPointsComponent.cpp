#include "DrawFromPointsComponent.hpp"

plt::DrawFromPointsComponent::DrawFromPointsComponent(getPointsFunction func, sf::Color color)
{
	this->func = func;

	va.setPrimitiveType(sf::PrimitiveType::TriangleStrip);

	for (sf::Vector2f p : *func())
	{
		va.append(sf::Vertex(p, color));
	}
}

void plt::DrawFromPointsComponent::setColor(sf::Color color)
{
	for (int i = 0; i < va.getVertexCount(); i++)
	{
		va[i].color = color;
	}
}

void plt::DrawFromPointsComponent::update(sf::Vector2f p)
{
	std::vector<sf::Vector2f>* v = func();

	for (int i = 0; i < v->size(); i++)
	{
		va[i].position = v->at(i);
	}
}

void plt::DrawFromPointsComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(va, states);
}