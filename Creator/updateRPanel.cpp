#include "Creator.hpp"

void Creator::updateRPanel()
{
	auto wind = gui.get<tgui::ChildWindow>("options");

	if (selected != nullptr)
	{
		auto posPanel = wind->get<tgui::Panel>("posPanel");

		if (posPanel == nullptr)
		{
			posPanel = tgui::Panel::create(tgui::Layout2d("&.width", 30));
			posPanel->setPosition(0, 0);

			auto posLabel = tgui::Label::create("Position:");
			posPanel->add(posLabel);

			auto posXBox = tgui::EditBox::create();
			posXBox->setSize("&.width / 3", 30);
			posXBox->setPosition("&.width / 3", 0);
			posXBox->setText(std::to_string((int)selected->getPosition().x));
			posXBox->setInputValidator(tgui::EditBox::Validator::UInt);
			posXBox->onReturnOrUnfocus([&](tgui::String text) {
				selected->setPosition(
					text,
					selected->getPosition().y
				);
			});
			posPanel->add(posXBox, "posXBox");

			auto posYBox = tgui::EditBox::create();
			posYBox->setSize("&.width / 3", 30);
			posYBox->setPosition("&.width * 2 / 3", 0);
			posYBox->setText(std::to_string((int)selected->getPosition().y));
			posYBox->setInputValidator(tgui::EditBox::Validator::UInt);
			posYBox->onReturnOrUnfocus([&](tgui::String text) {
				selected->setPosition(
					selected->getPosition().x,
					text
				);
			});
			posPanel->add(posYBox, "posYBox");

			wind->add(posPanel, "posPanel");

			auto wireButton = tgui::Button::create("Connect wire");
			wireButton->setPosition(0, 30);
			wireButton->setSize("&.width / 3", 30);
			wireButton->onClick([&]() {
				wireFirst = selected;
				wireing = true;
			});
			wind->add(wireButton);
		}
		else if (move)
		{
			posPanel->get<tgui::EditBox>("posXBox")->setText(std::to_string((int)selected->getPosition().x));
			posPanel->get<tgui::EditBox>("posYBox")->setText(std::to_string((int)selected->getPosition().y));
		}
	}
	else
	{
		wind->removeAllWidgets();
	}
}