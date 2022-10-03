#include "Creator.hpp"

void Creator::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		window.close();

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		if (sf::Mouse::getPosition().x < 1280 && sf::Mouse::getPosition().y < 720)
		{
			this->findWidget();

			if (selected != nullptr && wireing && wireFirst != selected)
			{

			}
		}
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
	{
		gui.get<tgui::ChildWindow>("mini")->remove(selected);
		this->setSelected(nullptr);
	}

	if (event.type == sf::Event::MouseMoved)
	{
		if (selected != nullptr && move)
		{
			this->updateSelected(tgui::Vector2f(
				sf::Mouse::getPosition().x - (selected->getSize().x / 2),
				sf::Mouse::getPosition().y - 29 - (selected->getSize().y / 2)
			));
		}
	}
}