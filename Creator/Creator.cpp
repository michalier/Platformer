#include "Creator.hpp"

Creator::Creator()
{
	this->selected = nullptr;
	move = false;
	wireing = false;
	this->loadUI();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			gui.handleEvent(event);
			this->handleEvent(event);
		}

		this->updateRPanel();

		window.clear();

		gui.draw();

		window.display();
	}
}