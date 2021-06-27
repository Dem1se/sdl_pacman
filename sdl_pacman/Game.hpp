#pragma once
#include "SDL.h"
#include "VideoManager.hpp"
#include "GameMode.hpp"

class Game
{
	static Game* _GameInstance;
	VideoManager* _VidMgr;
	GameMode* _GameMode;

public:
	static Game* Instance();
	void Load();
	void StartGameloop();
	void Exit();

private:
	Game();
};

