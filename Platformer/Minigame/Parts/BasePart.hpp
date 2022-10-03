#pragma once
#include <TGUI/TGUI.hpp>
#include <vector>
#include <functional>

namespace plt
{
    using inputFunction = std::function<bool(size_t nr) const>;

    class BasePart : public tgui::Picture
    {
    protected:
        Widget::Ptr clone() const override;

        std::vector<std::pair<BasePart*, size_t>> inputs;
        std::vector<bool> outputs;

        size_t ins, outs;
        bool evaled;

    public:
        typedef std::shared_ptr<BasePart> Ptr;
        typedef std::shared_ptr<const BasePart> ConstPtr;

        BasePart(size_t inN, size_t outN, const char* typeName = "MyCustomWidget", bool initRenderer = true);
        
        static BasePart::Ptr create(size_t inN, size_t outN);
        static BasePart::Ptr copy(BasePart::ConstPtr widget);

        bool getOutput(size_t nr) const;
        void connectInput(BasePart* p, size_t outNr, size_t inNr);

        size_t getInputCount() const;
        size_t getOutputCount() const;

        tgui::Vector2f getInputPos(size_t nr) const;
        tgui::Vector2f getOutputPos(size_t nr) const;

        std::vector<std::pair<BasePart*, size_t>> getInputs();

        virtual bool eval() { return false; }
    };
}