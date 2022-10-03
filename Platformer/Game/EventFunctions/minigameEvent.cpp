#include "../Game.hpp"

void plt::Game::minigameEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		window.close();

	Minigame::Ptr mi = gui.get<plt::Minigame>("terminalWindow");
	
	sf::Vector2i mouse = sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(8, 38);// -sf::Vector2i(3, 21);
	tgui::Vector2f mPos = sf::Vector2f(mouse.x - mi->getPosition().x, mouse.y - mi->getPosition().y);

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (mi->creating)
			{
				if (mPos.x < 1180)
					mi->findSelected(mPos);
			}
			else
				mi->findSelected(mPos);
			
		}

		if (event.mouseButton.button == sf::Mouse::Right)
		{
			if (mi->creating)
				mi->removeSelected();
		}
	}

	if (event.type == sf::Event::MouseMoved)
	{
		mi->moveSelected(mPos);
	}

	if (event.type == sf::Event::MouseButtonReleased)
	{
		mi->release(mPos);
	}

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
	{
		EndPart::Ptr ep = mi->get<EndPart>("end 1");
		auto wid = mi->getWidgets();
		for (auto w : wid)
		{
			std::cout << w->getWidgetName() << std::endl;
		}
		std::cout << "=========================" << std::endl;

		if (ep != nullptr)
		{
			bool r = ep->eval();

			if (r)
			{
				bool f = ep->getResult();
				std::cout << "valid " << (f ? "true" : "false") << std::endl;
			}
			else
			{
				std::cout << "invalid" << std::endl;
			}
		}
	}
}