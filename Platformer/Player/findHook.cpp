#include "Player.hpp"

void plt::Player::findHook()
{
	if (hookSelected != nullptr)
	{
		hookSelected->displayComponent->setColor(sf::Color::Black);
		if (Math::lenght(position - hookSelected->position) > hookLenght)
			hookSelected = nullptr;
	}

	if (hookSelected == nullptr)
	{
		auto hooks = level->getHooks(position, hookLenght);
		if (hooks->size() > 0)
			hookSelected = hooks->at(0);
	}

	if (hookSelected != nullptr)
		hookSelected->displayComponent->setColor(sf::Color::Cyan);
}

void plt::Player::selectHook(int o)
{
	if (hookSelected != nullptr)
	{
		auto v = level->getHooks(position, hookLenght);
		int a = 0;
		for (int i = 0; i < v->size(); i++)
		{
			if (v->at(i) == hookSelected)
				a = i;
		}

		hookSelected->displayComponent->setColor(sf::Color::Black);

		a += o;
		a = (a + v->size()) % v->size();
		hookSelected = v->at(a);

		hookSelected->displayComponent->setColor(sf::Color::Cyan);
	}
}