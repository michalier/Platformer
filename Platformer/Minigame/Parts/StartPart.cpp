#include "StartPart.hpp"

plt::StartPart::StartPart(bool ret, sf::Texture& t, size_t outN, const char* typeName, bool initRenderer) :
	BasePart(0, outN, typeName, initRenderer)
{
	this->getRenderer()->setTexture(t);
    outputs.push_back(ret);
}

plt::StartPart::Ptr plt::StartPart::create(bool ret, sf::Texture& t, size_t outN)
{
    return std::make_shared<StartPart>(ret, t, outN);
}

plt::StartPart::Ptr plt::StartPart::copy(StartPart::ConstPtr widget)
{
    if (widget)
        return std::static_pointer_cast<StartPart>(widget->clone());
    else
        return nullptr;
}

tgui::Widget::Ptr plt::StartPart::clone() const
{
    return std::make_shared<StartPart>(*this);
}

bool plt::StartPart::eval()
{
    return true;
}