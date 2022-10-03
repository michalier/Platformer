#include "Minigame.hpp"

void plt::Minigame::findSelected(tgui::Vector2f mPos)
{
	auto prev = selected;
	this->selected = nullptr;
	for (auto& w : plugs)
	{
		if (w->isMouseOnWidget(tgui::Vector2f(mPos.x, mPos.y)))
		{
			this->selected = w;
		}
	}

	if (creating)
	{
		for (auto& w : parts)
		{
			if (w->isMouseOnWidget(tgui::Vector2f(mPos.x, mPos.y)))
			{
				this->selected = w->cast<tgui::Picture>();
			}
		}

		if (selected != nullptr)
		{
			if (selected == prev)
			{
				if (moving)
					selected = nullptr;

				moving = !moving;
			}
			else
			{
				clearRPanel = true;
				if (connecting)
				{
					auto sel = selected->cast<BasePart>();

					if (sel->getOutputCount() == 1)
					{
						toConnect.first->connectInput(sel.get(), 1, toConnect.second);
					}
					else if (sel->getOutputCount() > 1)
					{
						size_t outs = sel->getOutputCount();
						auto w = tgui::ChildWindow::create("Select output");
						w->setSize(outs * 30, 60);
						w->setPosition(1180, 600);

						for (size_t i = 0; i < outs; i++)
						{
							auto b = tgui::Button::create(std::to_string(i + 1));
							b->setSize(30, 20);
							b->setPosition(i * 30, 0);
							b->onClick([&](size_t nr) {
								toConnect.first->connectInput(selected->cast<BasePart>().get(), nr, toConnect.second);
								this->get<ChildWindow>("outSelWindow")->close();
								//w->close();
							}, i + 1);

							w->add(b);
						}
						this->add(w, "outSelWindow");
					}

					connecting = false;
				}
			}
		}
	}
	else if (selected != nullptr)
	{
		for (auto p : parts)
		{
			if (p->getWidgetType() == "PlugHolder")
			{
				auto ph = p->cast<PlugHolder>();

				if (ph->isConnected(selected->cast<Plug>()))
					ph->connectPlug(nullptr);
			}
		}
	}
}

void plt::Minigame::moveSelected(tgui::Vector2f mPos)
{
	if (selected != nullptr)
	{
		if (creating)
		{
			if (moving)
				selected->setPosition(mPos.x - (selected->getSize().x / 2), mPos.y - (selected->getSize().y / 2));
		}
		else
		{
			selected->setPosition(mPos.x - (selected->getSize().x / 2), mPos.y - (selected->getSize().y / 2));
			//TODO adding to slots
			for (auto p : parts)
			{
				if (p->getWidgetType() == "PlugHolder")
				{
					auto ph = p->cast<PlugHolder>();

					if (ph->canAccept(mPos, selected->cast<Plug>().get()))
						selected->setPosition(ph->getPosition());
				}
			}
		}
	}
}

void plt::Minigame::release(tgui::Vector2f mPos)
{
	if (!creating)
	{
		if (selected != nullptr)
		{
			for (auto p : parts)
			{
				if (p->getWidgetType() == "PlugHolder")
				{
					auto ph = p->cast<PlugHolder>();

					if (ph->canAccept(mPos, selected->cast<Plug>().get()))
						ph->connectPlug(selected->cast<Plug>());
				}
			}
		}
		selected = nullptr;
	}
}

void plt::Minigame::removeSelected()
{
	if (selected != nullptr)
	{
		this->remove(selected);

		for (int i = 0; i < parts.size(); i++)
		{
			if (parts[i] == selected)
			{
				parts.erase(parts.begin() + i);
				break;
			}
		}

		selected = nullptr;
	}
}
