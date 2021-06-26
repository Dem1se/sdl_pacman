#pragma once
enum class TileSet
{
	Bottom,
	Left,
	BottomLeft,
	BottomBorder,
	LeftBorder,
	BottomLeftBorder,
	BottomLeftTee,
	Dot,
	Energizer,
	Blank
};

enum class TileSetFull
{
	Bottom,
	Top,
	Left,
	Right,
	BottomLeft,
	TopLeft,
	TopRight,
	BottomRight,
	BottomBorder,
	TopBorder,
	LeftBorder,
	RightBorder,
	BottomLeftBorder,
	TopLeftBorder,
	TopRightBorder,
	BottomRightBorder,
	BottomLeftTee,
	TopLeftTee,
	TopRightTee,
	BottomRightTee,
	Dot,
	Energizer,
	Blank
};

class Level
{
	int Map[36][28] = { 
		{ 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22 },
		{ 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22 },
		{ 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22 },
		{ 15, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 16, 19,  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 12 },
		{ 10, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 3, 2, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 11}
	};
public:
	Level();
	TileSetFull GetTile(int x, int y);
};

