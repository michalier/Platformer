#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class TexturePack
{
protected:
	

public:
	sf::Texture passPlug, negPlug, andPlug, oiooHolder, tiooHolder, startOn, startOff, finish;

	TexturePack()
	{
		passPlug.loadFromFile("C:/Users/Marcin/Desktop/Platformer/pass.png");
		negPlug.loadFromFile("C:/Users/Marcin/Desktop/Platformer/neg.png");
		andPlug.loadFromFile("C:/Users/Marcin/Desktop/Platformer/and.png");

		oiooHolder.loadFromFile("C:/Users/Marcin/Desktop/Platformer/oiooholder.png");
		tiooHolder.loadFromFile("C:/Users/Marcin/Desktop/Platformer/tiooholder.png");

		startOn.loadFromFile("C:/Users/Marcin/Desktop/Platformer/starton.png");
		startOff.loadFromFile("C:/Users/Marcin/Desktop/Platformer/startoff.png");

		finish.loadFromFile("C:/Users/Marcin/Desktop/Platformer/finish.png");
	}
};
