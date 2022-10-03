#include "Creator.hpp"
#include <windows.h>

void Creator::loadUI()
{
	window.create(sf::VideoMode(1920, 1080), "platformer maker");
	ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);

	gui.setTarget(window);

	sf::Texture selT;
	selT.loadFromFile("C:/Users/Marcin/Desktop/Platformer/selector.png");

	border = tgui::Picture::create(selT);
	
	auto minigameWindow = tgui::ChildWindow::create("minigame", tgui::ChildWindow::TitleButton::None);
	minigameWindow->setPosition(0, 0);
	minigameWindow->setSize(1280, 720);
	minigameWindow->onPositionChange([&](tgui::Vector2f pos) {
		if (pos != tgui::Vector2f(0, 0))
			gui.get("mini")->setPosition(0, 0);
	});

	gui.add(minigameWindow, "mini");

	auto optionsWindow = tgui::ChildWindow::create("options", tgui::ChildWindow::TitleButton::None);
	optionsWindow->setPosition(1280, 0);
	optionsWindow->setSize(640, 720);
	optionsWindow->onPositionChange([&](tgui::Vector2f pos)
	{
		if (pos != tgui::Vector2f(1280, 0))
			gui.get("options")->setPosition(1280, 0);
	});

	gui.add(optionsWindow, "options");

	auto partsWindow = tgui::ChildWindow::create("parts", tgui::ChildWindow::TitleButton::None);
	partsWindow->setPosition(0, 720);
	partsWindow->setSize(1920, 250);
	partsWindow->onPositionChange([&](tgui::Vector2f pos)
	{
		if (pos != tgui::Vector2f(0, 720))
			gui.get("parts")->setPosition(0, 720);
	});

	this->loadParts(partsWindow);

	gui.add(partsWindow, "parts");

}