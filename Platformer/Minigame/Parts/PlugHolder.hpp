#pragma once
#include "BasePart.hpp"
#include "Plug.hpp"

namespace plt
{
	class PlugHolder : public BasePart
	{
    protected:
        Widget::Ptr clone() const override;

        Plug::Ptr connected;

    public:
        std::string name;

        typedef std::shared_ptr<PlugHolder> Ptr;
        typedef std::shared_ptr<const PlugHolder> ConstPtr;

        PlugHolder(sf::Texture& t, size_t inN, size_t outN, const char* typeName = "PlugHolder", bool initRenderer = true);

        static PlugHolder::Ptr create(sf::Texture& t, size_t inN, size_t outN);
        static PlugHolder::Ptr copy(PlugHolder::ConstPtr widget);

        bool eval() override;

        bool canAccept(tgui::Vector2f mPos, Plug* plug);

        void connectPlug(Plug::Ptr plug) { this->connected = plug; }
        bool isConnected(Plug::Ptr plug) { return plug == connected; }
	};
}