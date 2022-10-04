#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include "TexturePack/TexturePack.hpp"

#include "../Minigame/Minigame.hpp"
#include "../Level/Level.hpp"
#include "../Player/Player.hpp"

namespace plt
{
	enum class GameState
	{
		MainMenu,
		Settings,
		LoadingLevel,
		GameLevel
	};

	class Game
	{
	protected:
		Level* level;
		Player* player;

		GameState state;

		sf::Font font;
		sf::Text debugText;

		TexturePack texturePack;

		tgui::GuiSFML gui;

		tgui::Widget::Ptr draggedWidget;
		sf::Vector2f widgetOffset;

	public:
		sf::RenderWindow window;
		
		Game();

		void setState(GameState state);

		void run();
		void handleEvent(sf::Event event);

		void minigameEvent(sf::Event event);
		void gameLevelEvent(sf::Event event);

		void loadLevel(int nr);

		void handleInput();
		void drawGame();

		void doEvent(std::string m);
	};
}
