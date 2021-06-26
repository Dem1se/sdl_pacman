#include "Game.hpp"

Game* Game::_GameInstance = nullptr;

Game::Game()
{
	_GameMode = new GameMode();
	_VidMgr = new VideoManager(_GameMode);
}

Game* Game::Instance()
{
	{
		if (!_GameInstance)
			_GameInstance = new Game();

		return _GameInstance;
	}
}

void Game::Initialize()
{
}

void Game::StartGameloop()
{
	while (1) {
		if (SDL_QuitRequested()) {
			break;
		}
		_GameMode->PlayerInst->Update();
		_VidMgr->Render();
		SDL_Delay(16); // wait 16 ms
	}
}

void Game::Exit()
{
	_VidMgr->Exit();
	SDL_Quit();
}

