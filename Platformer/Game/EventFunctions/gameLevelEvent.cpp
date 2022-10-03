#include "../Game.hpp"

void plt::Game::gameLevelEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		player->displayRange = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::E);

		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			window.close();
			break;

		case sf::Keyboard::Space:
			if (!player->hookDuty() && player->getState() != PlayerState::Jumping2)
				player->jumped = true;
			else if (player->getState() == PlayerState::HookFinished)
				player->setState(PlayerState::Falling);
			break;

		case sf::Keyboard::Q:
			if (!player->displayRange && player->getState() != PlayerState::HookShooting && player->getState() != PlayerState::HookPulling)
				player->selectHook(1);
			break;

		case sf::Keyboard::E:
		{
			for (Entity* e : level.elems)
			{
				if (e->interactComponent != nullptr)
					this->doEvent(e->interactComponent->check());
			}

			break;
		}
		case sf::Keyboard::LShift:
			if (player->getState() != PlayerState::HookShooting && player->getState() != PlayerState::HookPulling && player->hookSelected != nullptr)
				player->setState(PlayerState::HookShooting);
			break;
		}
	}
}