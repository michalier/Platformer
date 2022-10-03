#include "Creator.hpp"

void Creator::setSelected(tgui::Widget::Ptr w)
{
	this->selected = w;
	if (w == nullptr)
	{
		gui.get<tgui::ChildWindow>("mini")->remove(border);
	}
	else
	{
		gui.get<tgui::ChildWindow>("mini")->add(border);
		border->setPosition(w->getPosition());
	}
}

void Creator::updateSelected(tgui::Vector2f v)
{
	selected->setPosition(v);
	border->setPosition(v);
}