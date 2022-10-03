#include "Game.hpp"

void plt::Game::doEvent(std::string m)
{
	if (m == "test1")
	{
		player->setState(PlayerState::UsingTerminal);
		Minigame::Ptr win = Minigame::create(
			tgui::Theme::getDefault().get()->getRenderer("ChildWindow"), 
			texturePack, 
			"minigame", 
			tgui::ChildWindow::TitleButton::Close
		);
		
		win->onClosing([&](bool* abort) {
			*abort = false;
			player->setState(PlayerState::OnGround);
		});

		this->gui.add(win, "terminalWindow");
		
		win->loadUI();
		//win->load();
		win->redraw();
	}
}