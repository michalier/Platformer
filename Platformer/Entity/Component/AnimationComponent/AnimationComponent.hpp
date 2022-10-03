#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

namespace plt
{
	using moveFuncion = std::function<void>* (const sf::Vector2f&);

	class AnimationComponent
	{
	protected:

	public:
		AnimationComponent(moveFuncion func, sf::Vector2f dist, unsigned time);

		void addChain(AnimationComponent* ac);
		void update();

		void playAnimation();
		void reverseAnimation();
	};
}
