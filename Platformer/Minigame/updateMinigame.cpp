#include "Minigame.hpp"

void plt::Minigame::update()
{
	if (creating)
	{
		auto p = this->get<tgui::Panel>("panel");
		auto name = p->get<tgui::EditBox>("nameBox");
		auto posx = p->get<tgui::EditBox>("posx");
		auto posy = p->get<tgui::EditBox>("posy");
		
		if (selected == nullptr || clearRPanel)
		{
			name->setText("");
			posx->setText("");
			posy->setText("");

			auto con = p->get("conPanel");
			if (con != nullptr)
				p->remove(con);

			clearRPanel = false;
			connecting = false;
		}
		else
		{
			if (moving || posx->getText() == "")
			{
				name->setText(selected->getWidgetName());
				posx->setText(std::to_string((int)selected->getPosition().x));
				posy->setText(std::to_string((int)selected->getPosition().y));
			}

			if (p->get("conPanel") == nullptr)
			{
				auto pan = tgui::ScrollablePanel::create({ 145, 200 });
				pan->setPosition("&.width - 150", 60);

				auto s = selected->cast<BasePart>()->getInputs();
				size_t i = 0;
				for (auto& pa : s)
				{
					auto l = tgui::Label::create("input " + std::to_string(i + 1));
					l->setPosition(0, i * 30);
					l->setSize(70, 30);

					pan->add(l);

					auto b = tgui::Button::create();
					if (pa.first == nullptr)
					{
						b->setText("connect");
						b->onClick([&](size_t nr) {
							connect(nr + 1);
							//std::cout << "connect " << nr << std::endl;
						}, i);
					}
					else
					{
						b->setText(pa.first->getWidgetName());
						b->onClick([&](size_t nr) {
							connect(nr + 1, false);
							//std::cout << "connected" << std::endl;
						}, i);
					}

					b->setPosition(70, i * 30);
					b->setSize(80, 30);

					pan->add(b);
					i++;
				}

				p->add(pan, "conPanel");
			}
		}
	}

	this->redraw();
}

void plt::Minigame::connect(size_t number, bool connect)
{
	if (connect)
	{
		toConnect.first = selected->cast<BasePart>();
		toConnect.second = number;
		connecting = true;
	}
	else
	{
		selected->cast<BasePart>()->connectInput(nullptr, 0, number);
		clearRPanel = true;
	}
}