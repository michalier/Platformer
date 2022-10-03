#include "Line.hpp"
#include "Math.hpp"

#include <iostream>

plt::Line::Line(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

plt::Line::Line(sf::Vector2f p1, sf::Vector2f p2)
{
	this->p1 = p1;
	this->p2 = p2;

	float e = p2.y - p1.y;
	float f = p2.x - p1.x;

	this->a = -e;
	this->b = f;
	this->c = -f * p1.y + e * p1.x;
}

bool plt::Line::onLine(sf::Vector2f& p) const
{
	return p.x * a + c == p.y * -b &&
		   p.x >= std::min(p1.x, p2.x) && 
		   p.x <= std::max(p1.x, p2.x) &&
		   p.y >= std::min(p1.y, p2.y) &&
		   p.y <= std::max(p1.y, p2.y);
}

sf::Vector2f plt::Line::intersectPoint(Line& l) const
{
	return sf::Vector2f(
		(b * l.c - l.b * c) / (a * l.b - l.a * b),
		(c * l.a - l.c * a) / (a * l.b - l.a * b)
	);
}

float plt::Line::getAngle(const Line& l) const
{
	return Math::radToDeg(
		std::atan(
			(l.a * b - a * l.b) /
			(a * l.a + b * l.b)
		)
	);
}

void plt::Line::print() const
{
	std::cout << a << "x " << b << "y " << c << "c\n";
}