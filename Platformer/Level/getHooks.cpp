#include "Level.hpp"
#include "../Math/Math.hpp"

std::vector<plt::Entity*>* plt::Level::getHooks(sf::Vector2f pos, float range)
{
	std::vector<plt::Entity*>* v = new std::vector<plt::Entity*>();

	for (int i = 0; i < hookPoints.size(); i++)
	{
		if (Math::lenght(hookPoints[i]->position - pos) <= range)
			v->push_back(hookPoints[i]);
	}

	//std::sort(v->begin(), v->end(), [&](Entity* e1, Entity* e2) {
	//	return Math::lenght(e1->position - pos) < Math::lenght(e2->position - pos);
	//});

	return v;
}