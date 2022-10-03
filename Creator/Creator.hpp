#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class Creator
{
public:
	tgui::Widget::Ptr selected;
	tgui::Picture::Ptr border;
	bool move, wireing;

	tgui::Widget::Ptr wireFirst;

	Creator();
	void loadUI();
	void handleEvent(sf::Event event);
	void findWidget();

	void updateRPanel();
	void loadParts(tgui::ChildWindow::Ptr w);

	void setSelected(tgui::Widget::Ptr w);
	void updateSelected(tgui::Vector2f v);

	sf::RenderWindow window;
	tgui::GuiSFML gui;
};
