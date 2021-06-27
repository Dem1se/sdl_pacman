#pragma once
#include "SDL.h"
#include "TileSets.hpp"

class TileSheetHelper
{
	SDL_Surface *_TileSheet;

public:
	TileSheetHelper();
	~TileSheetHelper();
	SDL_Surface* GetSurfaceFromTileSheet(TileSetFull tile);
};
