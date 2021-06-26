#pragma once
#include "SDL.h"
#include "GameMode.hpp"

class VideoManager
{
public:
	float scaleX, scaleY;
	int width, height;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* tilesheet, *pacman;
	GameMode* _GameMode;
public:
	VideoManager(GameMode* GameModeInst);
	void Exit();
	void Render();
};
