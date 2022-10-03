#include "Creator.hpp"

void Creator::findWidget()
{
	auto widgs = gui.get<tgui::ChildWindow>("mini")->getWidgets();

	tgui::Vector2f mPos;
	mPos.x = sf::Mouse::getPosition().x;
	mPos.y = sf::Mouse::getPosition().y - 29;

	for (tgui::Widget::Ptr& w : widgs)
	{
		if (w->isMouseOnWidget(mPos))
		{
			if (selected == nullptr)
				this->setSelected(w);
			else if (!move)
			{
				if (w == selected)
					move = true;
				else
				{
					//selected = w;
					this->setSelected(w);
					gui.get<tgui::ChildWindow>("options")->removeAllWidgets();
				}
			}
			else
			{
				move = false;
				this->setSelected(w);
			}
			return;
		}
	}

	this->setSelected(nullptr);
}