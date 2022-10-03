#pragma once
#include "BasePart.hpp"

namespace plt
{
    class EndPart : public BasePart
    {
    protected:
        Widget::Ptr clone() const override;

    public:
        typedef std::shared_ptr<EndPart> Ptr;
        typedef std::shared_ptr<const EndPart> ConstPtr;

        EndPart(sf::Texture& t, size_t inN, const char* typeName = "EndPart", bool initRenderer = true);

        static EndPart::Ptr create(sf::Texture& t, size_t inN);
        static EndPart::Ptr copy(EndPart::ConstPtr widget);

        bool getResult() const { if (outputs.size() > 0) return outputs[0]; else return false; }
        bool eval() override;
    };
}