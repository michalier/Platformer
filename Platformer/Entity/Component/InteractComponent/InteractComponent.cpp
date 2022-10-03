#include "InteractComponent.hpp"
#include "../../../Math/Math.hpp"

plt::InteractComponent::InteractComponent(sf::Vector2f pos, std::string message, float range)
{
	this->position = pos;
	this->message = message;
	this->range = range;

	inRange = false;
}

void plt::InteractComponent::update(sf::Vector2f v)
{
	inRange = Math::lenght(v - position) <= range;
}

std::string plt::InteractComponent::check() const
{
	if (inRange)
		return this->message;
	else
		return "";
}

void plt::InteractComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (inRange && popup != nullptr)
		target.draw(*popup, states);
}
