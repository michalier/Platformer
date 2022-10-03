#include "Plug.hpp"

plt::Plug::Plug(plugFunc func, sf::Texture& t, size_t inN, size_t outN, const char* typeName, bool initRenderer) : tgui::Picture(typeName, initRenderer)
{
	this->getRenderer()->setTexture(t);
    this->func = func;

    this->ins = inN;
    this->outs = outN;
}

plt::Plug::Ptr plt::Plug::create(plugFunc func, sf::Texture& t, size_t inN, size_t outN)
{
    return std::make_shared<Plug>(func, t, inN, outN);
}

plt::Plug::Ptr plt::Plug::copy(Plug::ConstPtr widget)
{
    if (widget)
        return std::static_pointer_cast<Plug>(widget->clone());
    else
        return nullptr;
}

tgui::Widget::Ptr plt::Plug::clone() const
{
    return std::make_shared<Plug>(*this);
}