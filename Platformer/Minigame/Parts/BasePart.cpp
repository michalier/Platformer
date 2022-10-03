#include "BasePart.hpp"

plt::BasePart::BasePart(size_t inN, size_t outN, const char* typeName, bool initRenderer) : tgui::Picture(typeName, initRenderer)
{
    this->ins = inN;
    this->outs = outN;

    evaled = false;

    for (int i = 0; i < ins; i++)
    {
        inputs.push_back(std::pair<BasePart*, size_t>(nullptr, 0));
    }
}

plt::BasePart::Ptr plt::BasePart::create(size_t inN, size_t outN)
{
    return std::make_shared<BasePart>(inN, outN);
}

plt::BasePart::Ptr plt::BasePart::copy(BasePart::ConstPtr widget)
{
    if (widget)
        return std::static_pointer_cast<BasePart>(widget->clone());
    else
        return nullptr;
}

tgui::Widget::Ptr plt::BasePart::clone() const
{
    return std::make_shared<BasePart>(*this);
}