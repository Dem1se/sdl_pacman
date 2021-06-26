#include "Level.hpp"

Level::Level()
{
}

TileSetFull Level::GetTile(int x, int y)
{
	return (TileSetFull)Map[x][y];
}
