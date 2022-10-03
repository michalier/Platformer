#include "Minigame.hpp"

void plt::Minigame::redraw()
{
	auto canv = this->get<tgui::CanvasSFML>("canvas");

	canv->clear(tgui::Color::White);

	for (auto p : parts)
	{
		auto ins = p->getInputs();

		for (size_t i = 0; i < ins.size(); i++)
		{
			if (ins[i].first != nullptr)
			{
				tgui::Color c;
				if (ins[i].first->eval())
				{
					if (ins[i].first->getOutput(ins[i].second))
						c = tgui::Color::Cyan;
					else
						c = tgui::Color::Black;
				}
				else
					c = tgui::Color::Red;

				this->drawWire(
					canv,
					p->getInputPos(i + 1),
					ins[i].first->getOutputPos(ins[i].second),
					c
				);
			}
		}
	}

	canv->display();
}

void plt::Minigame::drawWire(tgui::CanvasSFML::Ptr canv, tgui::Vector2f p1, tgui::Vector2f p2, tgui::Color c)
{
	float dy = p1.y + (p2.y - p1.y) / 2;

	sf::RectangleShape rs1;
	rs1.setPosition(p1);
	rs1.setOrigin(2, 2);
	rs1.setSize(sf::Vector2f(4, dy - p1.y + 4));
	rs1.setFillColor(c);

	canv->draw(rs1);

	sf::RectangleShape rs2;
	rs2.setPosition(p1.x, dy);
	rs2.setOrigin(2, 2);
	rs2.setSize(sf::Vector2f(p2.x - p1.x + 4, 4));
	rs2.setFillColor(c);

	canv->draw(rs2);

	sf::RectangleShape rs3;
	rs3.setPosition(p2.x, dy);
	rs3.setOrigin(2, 2);
	rs3.setSize(sf::Vector2f(4, p2.y - dy + 4));
	rs3.setFillColor(c);

	canv->draw(rs3);
}