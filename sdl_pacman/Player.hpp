#pragma once
#include <SDL.h>

struct Position { /* pos of pacman's center */ float x, y; };
enum class Direction {Up, Down, Left, Right};

class Player
{
	int _BaseSpeed; // 88px per sec
	Position _Pos;
	SDL_Event _InputEvent;
	Direction _Direction;
	
public:
	Player();
	void Update();
	Position GetPosition();

private:
	bool IsInputKey(SDL_Event ev);
};
