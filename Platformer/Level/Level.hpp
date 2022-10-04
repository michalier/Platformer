#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../Entity/Entity.hpp"

namespace plt
{
	class Level : public sf::Drawable
	{
	protected:
		std::vector<Entity*> hookPoints;

	public:
		sf::FloatRect space;

		std::vector<Entity*> elems;
		unsigned progress;
		Level();

		void load(sf::Font* font, std::string name);
		void update(sf::Vector2f pos);
		std::vector<Entity*>* getHooks(sf::Vector2f pos, float range);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
