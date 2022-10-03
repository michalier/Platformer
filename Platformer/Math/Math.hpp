#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

namespace plt
{
	class Math
	{
	public:
		template<class T>
		static T lenght(sf::Vector2<T> v)
		{
			return std::sqrt(v.x * v.x + v.y * v.y);
		}

		template<class T>
		static float angle(sf::Vector2<T> p1, sf::Vector2<T> p2)
		{
			return Math::radToDeg(atan2(p1.y - p2.y, p1.x - p2.x)) + 90;
		}

		static float degToRad(float d);
		static float radToDeg(float r);

		static const float PI;
	};
}