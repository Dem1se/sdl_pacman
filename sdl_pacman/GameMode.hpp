#pragma once
#include "Player.hpp"
#include "Level.hpp"
#include "TileSets.hpp"

class GameMode
{
	Player* _PlayerInst;
	Level* _Level;
public:
	unsigned int Score, Lives, DotsEaten;
	// fruits
	// player
	// ghostManager
	// Map
	
public:
	GameMode();
	~GameMode();
	void Tick();
	TileSetFull LevelGetTile(int x, int y);
	Position GetPlayerPosition();
};

