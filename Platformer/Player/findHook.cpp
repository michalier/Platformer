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

		delete hooks;
	}

	if (hookSelected != nullptr)
		hookSelected->displayComponent->setColor(sf::Color::Cyan);
}

void plt::Player::selectHook(int o)
{
	if (hookSelected != nullptr)
	{
		auto hooks = level->getHooks(position, hookLenght);
		int a = 0;
		for (int i = 0; i < hooks->size(); i++)
		{
			if (hooks->at(i) == hookSelected)
				a = i;
		}

		hookSelected->displayComponent->setColor(sf::Color::Black);

		a += o;
		a = (a + hooks->size()) % hooks->size();
		hookSelected = hooks->at(a);

		hookSelected->displayComponent->setColor(sf::Color::Cyan);

		delete hooks;
	}
}