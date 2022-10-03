#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <fstream>
#include <vector>

#include "../Game/TexturePack/TexturePack.hpp"

#include "Parts/BasePart.hpp"
#include "Parts/PlugHolder.hpp"
#include "Parts/StartPart.hpp"
#include "Parts/EndPart.hpp"

#define DEBUG

// TODO
//
// - Saving minigame
//


namespace plt
{
	class Minigame : public tgui::ChildWindow
	{
	protected:

		std::vector<BasePart::Ptr> parts;
		std::vector<Plug::Ptr> plugs;

        tgui::Picture::Ptr selected;

        sf::Vector2f widgetOffset;

        TexturePack t;
        bool moving, clearRPanel, connecting;

        std::pair<BasePart::Ptr, size_t> toConnect;

        BasePart::Ptr templates[6];

	public:
        bool creating;
        typedef std::shared_ptr<Minigame> Ptr;
        typedef std::shared_ptr<const Minigame> ConstPtr;

        Minigame(const char* typeName = "Minigame", bool initRenderer = true);
        static Minigame::Ptr create(
            std::shared_ptr<tgui::RendererData> renderer, 
            TexturePack& textures, 
            const tgui::String& title = "", 
            unsigned int titleButtons = TitleButton::Close
        );
        static Minigame::Ptr copy(Minigame::ConstPtr widget);

        void load();
        void loadUI();
        void redraw();
        void drawWire(tgui::CanvasSFML::Ptr canv, tgui::Vector2f p1, tgui::Vector2f p2, tgui::Color c);
        void update();
        void removeSelected();
        void connect(size_t number, bool connect = true);

        void findSelected(tgui::Vector2f mPos);
        void moveSelected(tgui::Vector2f mPos);
        void release(tgui::Vector2f mPos);
	};
}
