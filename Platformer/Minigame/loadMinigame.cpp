#include "Minigame.hpp"

void plt::Minigame::load()
{
    BasePart::Ptr p = EndPart::create(t.finish, 1);
    p->setWidgetName("end 1");
    p->setPosition(50, 50);

    parts.push_back(p);
    this->add(p, p->getWidgetName());
        
    p = PlugHolder::create(t.oiooHolder, 1, 1);
    p->setWidgetName("plug 1");
    p->setPosition(50, 150);

    parts.push_back(p);
    this->add(p, p->getWidgetName());
    
    this->get<BasePart>("end 1")->connectInput(this->get<BasePart>("plug 1").get(), 1, 1);

    auto pr = StartPart::create(true, t.startOn, 1);
    pr->setWidgetName("start 1");
    pr->setPosition(50, 450);

    parts.push_back(pr);
    this->add(pr, pr->getWidgetName());

    this->get<PlugHolder>("plug 1")->connectInput(this->get<StartPart>("start 1").get(), 1, 1);

    auto pl = Plug::createPass(t.passPlug);
    pl->setPosition("&.width - 115", 30);

    this->plugs.push_back(pl);
    this->add(pl);

    pl = Plug::createNeg(t.negPlug);
    pl->setPosition("&.width - 115", 130);

    this->plugs.push_back(pl);
    this->add(pl);


}