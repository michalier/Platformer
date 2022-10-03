#pragma once
#include <TGUI/TGUI.hpp>

#include "BasePart.hpp"

namespace plt
{
	class StartPart : public BasePart
	{
    protected:
        Widget::Ptr clone() const override;

    public:
        typedef std::shared_ptr<StartPart> Ptr;
        typedef std::shared_ptr<const StartPart> ConstPtr;

        StartPart(bool ret, sf::Texture& t, size_t outN, const char* typeName = "StartPart", bool initRenderer = true);

        static StartPart::Ptr create(bool ret, sf::Texture& t, size_t outN);
        static StartPart::Ptr copy(StartPart::ConstPtr widget);

        bool eval() override;
	};
}
