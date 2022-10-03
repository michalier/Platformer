#include "Math.hpp"

const float plt::Math::PI = 3.14159265359f;

float plt::Math::degToRad(float d)
{
	return d / 180.f * PI;
}

float plt::Math::radToDeg(float r)
{
	return r / PI * 180.f;
}
