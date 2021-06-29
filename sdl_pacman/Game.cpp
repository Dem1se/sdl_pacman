#include "Game.hpp"

Game* Game::_GameInstance = nullptr;

Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
	}
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

void Game::Load()
{
	_VidMgr->Load();
}

void Game::StartGameloop()
{
	unsigned int tickStart, tickEnd, delta;

	while (1) {
		tickStart = SDL_GetTicks();
		if (SDL_QuitRequested()) break;

		_GameMode->Tick();
		_VidMgr->Render();

		// Framerate locking
		tickEnd = SDL_GetTicks();
		delta = SDL_TICKS_PASSED(tickEnd, tickStart);
		SDL_Delay((int)(16.67 - delta)); // Max framerate is ~60
	}
}

void Game::Exit()
{
	_VidMgr->~VideoManager();
	_GameMode->~GameMode();
	SDL_Quit();
}

