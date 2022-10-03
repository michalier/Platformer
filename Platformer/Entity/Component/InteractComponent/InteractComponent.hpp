#pragma once
#include <SFML/Graphics.hpp>

namespace plt
{
	class InteractComponent : public sf::Drawable
	{
	protected:
		sf::Vector2f position;
		std::string message;
		float range;

		bool inRange;

	public:
		sf::Drawable* popup;
		InteractComponent(sf::Vector2f pos, std::string message, float range);

		void update(sf::Vector2f v);
		std::string check() const;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}