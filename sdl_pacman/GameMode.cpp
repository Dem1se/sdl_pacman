#include "GameMode.hpp"

GameMode::GameMode()
{
	_PlayerInst = new Player();
	_Level = new Level();
	Score = 0;
	Lives = 2;
	DotsEaten = 0;
}

GameMode::~GameMode()
{
	_PlayerInst->~Player();
	_Level->~Level();
}

void GameMode::Tick()
{
	_PlayerInst->Update();
}

TileSetFull GameMode::LevelGetTile(int x, int y)
{
	return _Level->GetTile(x, y);
}

Position GameMode::GetPlayerPosition()
{
	return _PlayerInst->GetPosition();	
}
