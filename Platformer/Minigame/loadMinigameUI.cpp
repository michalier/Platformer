#include "Minigame.hpp"

void plt::Minigame::loadUI()
{
    this->removeAllWidgets();
    this->plugs.clear();
    this->parts.clear();

    auto canv = tgui::CanvasSFML::create();
    canv->setSize("&.width - 150", "&.height");

    this->add(canv, "canvas");

#ifdef DEBUG
    auto createButton = tgui::Button::create("create");
    createButton->setPosition("&.width - 150", "&.height - 60");
    createButton->setSize(150, 30);
    createButton->onClick([&]() {
        creating = !creating;
        this->setTitle((creating ? "creating minigame" : "minigame"));
        this->loadUI();
        this->redraw();
    });

    this->add(createButton);
#endif

    if (creating)
    {
        auto scroll = tgui::ScrollablePanel::create({ 145, 300 });
        scroll->setPosition("&.width - 150", 0);
        scroll->getRenderer()->setBorderColor(tgui::Color::Black);
        scroll->getRenderer()->setBorders(2);
        scroll->setVerticalScrollbarPolicy(tgui::Scrollbar::Policy::Always);
        scroll->setHorizontalScrollbarPolicy(tgui::Scrollbar::Policy::Never);

        int* nr = new int(1);
        int i = 0;
        int x = (int)((55 - scroll->getScrollbarWidth()) / 2);
        for (auto& ta : templates)
        {
            auto b = tgui::BitmapButton::create();
            
            b->getRenderer()->setTexture(ta->getRenderer()->getTexture());

            b->setPosition(x, 10 + (i * 110));
            b->setSize(100, 100);

            b->onClick([&](int* nr) {
                auto w = BasePart::copy(ta);
                w->setWidgetName(ta->getWidgetName() + std::to_string(*nr));
                *nr += 1;
                parts.push_back(w);
                selected = w;
                this->add(w, w->getWidgetName());
                moving = true;
            }, nr);

            scroll->add(b);
            i++;
        }
        
        this->add(scroll);

        auto panel = tgui::Panel::create({ 150, 350 });
        panel->setPosition("&.width - 150", 300);

        auto l = tgui::Label::create("Name");
        l->setSize(50, 30);

        panel->add(l);

        auto tf = tgui::EditBox::create();
        tf->setSize(100, 30);
        tf->setPosition(50, 0);
        tf->onReturnOrUnfocus([&]() {
            if (selected != nullptr)
                selected->setWidgetName(get<tgui::Panel>("panel")->get<tgui::EditBox>("nameBox")->getText());
        });

        panel->add(tf, "nameBox");

        l = tgui::Label::create("Position");
        l->setSize(80, 30);
        l->setPosition(0, 30);

        panel->add(l);

        tf = tgui::EditBox::create();
        tf->setSize(50, 30);
        tf->setPosition(50, 30);
        tf->setInputValidator(tgui::EditBox::Validator::UInt);
        tf->onReturnOrUnfocus([&]() {
            if (selected != nullptr)
                selected->setPosition(get<tgui::Panel>("panel")->get<tgui::EditBox>("posx")->getText(), selected->getPosition().y);
        });

        panel->add(tf, "posx");

        tf = tgui::EditBox::create();
        tf->setSize(50, 30);
        tf->setPosition(100, 30);
        tf->setInputValidator(tgui::EditBox::Validator::UInt);
        tf->onReturnOrUnfocus([&]() {
            if (selected != nullptr)
                selected->setPosition(selected->getPosition().x, get<tgui::Panel>("panel")->get<tgui::EditBox>("posy")->getText());
        });

        panel->add(tf, "posy");

        this->add(panel, "panel");
    }
    else
    {
        this->load();
    }
}