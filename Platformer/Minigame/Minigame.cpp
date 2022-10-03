#include "Minigame.hpp"

plt::Minigame::Minigame(const char* typeName, bool initRenderer) : tgui::ChildWindow(typeName, initRenderer)
{
    this->setSize("&.width", "&.height");
    this->setPosition(0, 0);

    this->moving = false;
    this->creating = false;
    this->selected = nullptr;
    this->clearRPanel = false;

    templates[0] = StartPart::create(true, t.startOn, 1);
    templates[0]->setWidgetName("start ");
    templates[1] = StartPart::create(false, t.startOff, 1);
    templates[1]->setWidgetName("start ");
    templates[2] = PlugHolder::create(t.oiooHolder, 1, 1);
    templates[2]->setWidgetName("plug ");
    templates[3] = PlugHolder::create(t.tiooHolder, 2, 1);
    templates[3]->setWidgetName("plug ");
    templates[4] = EndPart::create(t.finish, 1);
    templates[4]->setWidgetName("end ");
    templates[5] = PlugHolder::create(t.tiooHolder, 1, 2);
    templates[5]->setWidgetName("plug ");
}

plt::Minigame::Ptr plt::Minigame::create(
    std::shared_ptr<tgui::RendererData> renderer, 
    TexturePack& textures, 
    const tgui::String& title, 
    unsigned int titleButtons
)
{
    auto w = std::make_shared<plt::Minigame>();

    w->setTitle(title);
    w->setTitleButtons(titleButtons);

    w->setRenderer(renderer);

    w->onPositionChange([&](tgui::Vector2f pos) {
        if (pos != tgui::Vector2f(0, 0))
            w->setPosition(0, 0);
    });

    w->t = textures;

    return w;
}

plt::Minigame::Ptr plt::Minigame::copy(Minigame::ConstPtr widget)
{
    if (widget)
        return std::static_pointer_cast<Minigame>(widget->clone());
    else
        return nullptr;
}