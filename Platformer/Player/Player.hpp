#pragma once
#include "../Entity/Entity.hpp"
#include "../Level/Level.hpp"
#include "../Entity/Component/PhysicsComponent/PhysicsComponent.hpp"
#include "../Math/Line.hpp"
#include "../Math/Math.hpp"

namespace plt
{
	enum PlayerState
	{
		OnGround = 0,
		Jumping = 1,
		Jumping2 = 2,
		Falling = 3,
		HookShooting = 4,
		HookPulling = 5,
		HookFinished = 6,
		UsingTerminal = 7
	};

	class Player : public Entity
	{
	protected:
		sf::View playerView;
		

		float hookLenght, hookSpeed;
		sf::CircleShape hookRange;
		sf::RectangleShape hookLine;
		sf::Vector2f hookOffset;
		
		int state;
		
	public:
		Level* level;
		bool jumped, displayRange;
		
		Entity* hookSelected;

		PhysicsComponent* physicsComponent;

		Player(sf::Vector2f position);
		static Player* summon(sf::Vector2f position);

		void setState(int s);
		int getState() const;
		std::string stateToString() const;
		bool hookDuty() const;

		void updatePlayer();
		void checkCollisions();
		void move(sf::Vector2f vec);
		void findHook();
		void selectHook(int o);

		sf::View& getView();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}