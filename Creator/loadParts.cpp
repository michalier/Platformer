#include "Creator.hpp"

void Creator::loadParts(tgui::ChildWindow::Ptr w)
{
	sf::Texture t[6];
	std::string s[6] = {
		"StartOn",
		"StartOff",
		"OneInOneOut",
		"TwoInOneOut",
		"Finish",
		"Bad Finish"
	};

	t[0].loadFromFile("C:/Users/Marcin/Desktop/Platformer/starton.png");
	t[1].loadFromFile("C:/Users/Marcin/Desktop/Platformer/startoff.png");
	t[2].loadFromFile("C:/Users/Marcin/Desktop/Platformer/oiooholder.png");
	t[3].loadFromFile("C:/Users/Marcin/Desktop/Platformer/tiooholder.png");
	t[4].loadFromFile("C:/Users/Marcin/Desktop/Platformer/finish.png");
	t[5].loadFromFile("C:/Users/Marcin/Desktop/Platformer/badfinish.png");

	for (int i = 0; i < 6; i++)
	{
		auto b = tgui::BitmapButton::create(s[i]);
		b->setImage(t[i]);
		b->setSize(t[i].getSize().x + 110, t[i].getSize().y);
		b->setPosition(((b->getSize().x + 10) * i) + 30, 30);
		b->onClick([&, i]() {
			auto s = tgui::Picture::create(gui.
				get<tgui::ChildWindow>("parts")->
				get<tgui::BitmapButton>("b" + std::to_string(i))->getImage()
			);

			//s->getRenderer()->setTransparentTexture(false);
			s->setPosition(
				sf::Mouse::getPosition().x - (s->getSize().x / 2),
				sf::Mouse::getPosition().y - 29 - (s->getSize().y / 2)
			);

			this->setSelected(s);
			gui.get<tgui::ChildWindow>("mini")->add(selected);
			move = true;
		});

		w->add(b, "b" + std::to_string(i));
	}
}