#include "Player.hpp"

void plt::Player::setState(int s)
{
	this->state = s;
}

int plt::Player::getState() const
{
	return this->state;
}

bool plt::Player::hookDuty() const
{
	return state == PlayerState::HookShooting || state == PlayerState::HookPulling || state == PlayerState::HookFinished;
}

std::string plt::Player::stateToString() const
{
	switch (this->state)
	{
	case OnGround:
		return "OnGround";
	case Jumping:
		return "Jumping";
	case Jumping2:
		return "Jumping2";
	case Falling:
		return "Falling";
	case HookShooting:
		return "HookShooting";
	case HookPulling:
		return "HookPulling";
	case HookFinished:
		return "HookFinished";
	case UsingTerminal:
		return "UsingTerminal";
	default:
		return "Error";
	}
}