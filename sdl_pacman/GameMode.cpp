#include "GameMode.hpp"

GameMode::GameMode()
{
	PlayerInst = new Player();
	Score = 0;
	Lives = 2;
	DotsEaten = 0;
}
