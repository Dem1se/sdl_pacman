#include "Level.hpp"

Level::Level()
{
}

Level::~Level()
{
    // Nothing allocated on the heap
}

TileSetFull Level::GetTile(int x, int y)
{
	return (TileSetFull)Map[y][x];
}

TilePos Level::GetPosInTiles(int PosX, int PosY)
{
    int x = PosX / 8;
    int y = PosY / 8;

    return TilePos{ x, y };
}
