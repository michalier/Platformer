#include "EndPart.hpp"

plt::EndPart::EndPart(sf::Texture& t, size_t inN, const char* typeName, bool initRenderer) :
	BasePart(inN, 0, typeName, initRenderer)
{
	this->getRenderer()->setTexture(t);
}

plt::EndPart::Ptr plt::EndPart::create(sf::Texture& t, size_t inN)
{
    return std::make_shared<EndPart>(t, inN);
}

plt::EndPart::Ptr plt::EndPart::copy(EndPart::ConstPtr widget)
{
    if (widget)
        return std::static_pointer_cast<EndPart>(widget->clone());
    else
        return nullptr;
}

tgui::Widget::Ptr plt::EndPart::clone() const
{
    return std::make_shared<EndPart>(*this);
}

bool plt::EndPart::eval()
{
    outputs.clear();
    for (auto& i : inputs)
    {
        if (i.first == nullptr || !i.first->eval())
            return false;

        outputs.push_back(i.first->getOutput(i.second));
    }

    return true;
}