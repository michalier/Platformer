#include "Player.hpp"

#include <iostream>

void plt::Player::updatePlayer()
{
	if (this->hookDuty())
	{
		switch (state)
		{
		case PlayerState::HookShooting:
		{
			if (vector.y < 20)
				this->vector += physicsComponent->getVector();

			this->move(vector);
			this->checkCollisions();

			this->displayComponent->update(sf::Vector2f(0, 0));

			// ================================================================

			hookLine.setRotation(Math::angle(hookLine.getPosition(), hookSelected->position));
			float l = Math::lenght(hookLine.getPosition() - hookSelected->position);

			if (l < hookLenght)
			{
				if (hookLine.getSize().y + hookSpeed < l)
					hookLine.setSize(hookLine.getSize() + sf::Vector2f(0, hookSpeed));
				else
				{
					hookLine.setSize(sf::Vector2f(hookLine.getSize().x, l));
					this->setState(PlayerState::HookPulling);
				}
			}
			else
			{
				this->setState(PlayerState::Falling);
			}
			break;
		}
		case PlayerState::HookPulling:
		{
			float l = Math::lenght(hookLine.getPosition() - hookSelected->position);
			sf::Vector2f off;
			if (l - hookSpeed > 0)
			{
				float a = hookLine.getRotation() + 90;

				off.x = cosf(Math::degToRad(a)) * hookSpeed;
				off.y = sinf(Math::degToRad(a)) * hookSpeed;

				hookLine.setSize(hookLine.getSize() - sf::Vector2f(0, hookSpeed));
			}
			else
			{
				off = hookSelected->position - hookLine.getPosition();
				hookLine.setSize(sf::Vector2f(hookLine.getSize().x, 0));
				this->setState(PlayerState::HookFinished);
			}

			this->move(off);
			this->displayComponent->update(sf::Vector2f(0, 0));
		}
		case PlayerState::HookFinished:
		{
			this->vector = sf::Vector2f(0, 0);
		}
		default:
			break;
		}
	}
	else
	{
		if (vector.y < 20)
			this->vector += physicsComponent->getVector();

		if (jumped && state != PlayerState::Jumping2)
		{
			if (state == PlayerState::Falling || state == PlayerState::OnGround)
				this->setState(PlayerState::Jumping);
			else if (state == PlayerState::Jumping)
				this->setState(PlayerState::Jumping2);

			vector.y = -10;
			jumped = false;
		}

		if (vector.y > 0 && state != PlayerState::Jumping && state != PlayerState::Jumping2)
			this->setState(PlayerState::Falling);

		this->move(vector);
		this->checkCollisions();

		this->displayComponent->update(sf::Vector2f(0, 0));

		this->findHook();
	}
}