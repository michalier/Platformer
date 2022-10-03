#pragma once
#include <SFML/Graphics.hpp>

namespace plt
{
	class Line
	{
	protected:
		float a, b, c;

	public:
		sf::Vector2f p1, p2;
		
		Line(float a, float b, float c);
		Line(sf::Vector2f p1, sf::Vector2f p2);

		bool onLine(sf::Vector2f& p) const;
		sf::Vector2f intersectPoint(Line& l) const;

		bool intersects(Line& l) const { 
			sf::Vector2f p = intersectPoint(l);
			return onLine(p) && l.onLine(p); 
		}

		bool operator==(Line& l)
		{
			return a == l.a && b == l.b && c == l.c;
		}

		bool operator!=(Line& l)
		{
			return !(*this == l);
		}

		float getAngle(const Line& l) const;

		void print() const;
	};
}
