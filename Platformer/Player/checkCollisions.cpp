#include "Player.hpp"

void plt::Player::checkCollisions()
{
	for (Entity* e : level->elems)
	{
		if (e->collisionComponent != nullptr)
		{
			if (collisionComponent->collides(e->collisionComponent))
			{
				sf::Vector2f off;
				bool eqX = false, eqY = false;

				if (vector.x > 0)
				{
					off.x = e->collisionComponent->getLeft() - collisionComponent->getRight();
					if (off.x == 0)
						eqX = true;
				}
				else if (vector.x < 0)
				{
					off.x = e->collisionComponent->getRight() - collisionComponent->getLeft();
					if (off.x == 0)
						eqX = true;
				}
				else
				{
					if (e->collisionComponent->getRight() == collisionComponent->getLeft() ||
						e->collisionComponent->getLeft() == collisionComponent->getRight())
						eqX = true;

					off.x = 0;
				}


				if (vector.y > 0)
				{
					off.y = e->collisionComponent->getTop() - collisionComponent->getBottom();
					if (off.y == 0)
						eqY = true;
				}
				else if (vector.y < 0)
				{
					off.y = e->collisionComponent->getBottom() - collisionComponent->getTop();
					if (off.y == 0)
						eqY = true;
				}
				else
				{
					if (e->collisionComponent->getTop() == collisionComponent->getBottom() ||
						e->collisionComponent->getBottom() == collisionComponent->getTop())
						eqY = true;

					off.y = 0;
				}

				float mov;

				if (off.x != 0 && off.y != 0)
				{
					if (std::abs(off.x) < std::abs(off.y))
						mov = off.x;
					else
						mov = off.y;
				}
				else
				{
					if (off.x == 0 && !eqX)
						mov = off.y;
					else if (off.y == 0 && !eqY)
						mov = off.x;
					else
						mov = 0;
				}

				if (mov != 0)
				{
					if (mov == off.x && vector.x != 0)
					{
						this->move(sf::Vector2f(off.x, 0));
						vector.x = 0;
					}
					else if (vector.y != 0)
					{
						if (vector.y > 0 && !hookDuty())
							this->setState(PlayerState::OnGround);

						this->move(sf::Vector2f(0, off.y));
						vector.y = 0;
					}
				}
				else
				{
					if (eqX)
						vector.x = 0;

					if (eqY)
					{
						if (vector.y > 0 && !hookDuty())
							this->setState(PlayerState::OnGround);

						vector.y = 0;
					}
				}
			}
		}
	}
}