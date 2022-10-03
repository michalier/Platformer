#pragma once
#include <TGUI/TGUI.hpp>
#include <functional>
#include <vector>

namespace plt
{
	using plugFunc = std::function<std::vector<bool>(std::vector<bool>& in)>;

	class Plug : public tgui::Picture
	{
    protected:
        Widget::Ptr clone() const override;

        plugFunc func;
        size_t ins, outs;

    public:
        typedef std::shared_ptr<Plug> Ptr;
        typedef std::shared_ptr<const Plug> ConstPtr;

        Plug(plugFunc func, sf::Texture& t, size_t inN, size_t outN, const char* typeName = "Plug", bool initRenderer = true);

        static Plug::Ptr create(plugFunc func, sf::Texture& t, size_t inN, size_t outN);
        static Plug::Ptr copy(Plug::ConstPtr widget);

        size_t getInputCount() const { return ins; }
        size_t getOutputCount() const { return outs; }

        std::vector<bool> eval(std::vector<bool>& in)
        {
            return func(in);
        }

        static Plug::Ptr createPass(sf::Texture& t)
        {
            return Plug::create([](std::vector<bool>& in) -> std::vector<bool>
            {
                std::vector<bool> o;
                o.push_back(in[0]);
                return o;
            }, t, 1, 1);
        }

        static Plug::Ptr createNeg(sf::Texture& t)
        {
            return Plug::create([](std::vector<bool>& in) -> std::vector<bool>
            {
                std::vector<bool> o;
                o.push_back(!in[0]);
                return o;
            }, t, 1, 1);
        }
	};
}