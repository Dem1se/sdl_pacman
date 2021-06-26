#pragma once
#include "SDL.h"
#include "Level.hpp"

struct TilePos
{
	int x, y;
};

class TileSheetHelper
{
	SDL_Surface* _TileSheet = SDL_LoadBMP("C:/Users/Dem1se/Source/Repos/sdl_pacman/sdl_pacman/Assets/tilesheet.bmp");
	SDL_Renderer* _RenderingContext;
public:
	TileSheetHelper(SDL_Renderer* renderer);
	TilePos GetTile(int PosX, int PosY);
	SDL_Texture* GetTextureFromTileSheet(TileSetFull tile);

};

