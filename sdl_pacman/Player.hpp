#pragma once
#include <SDL.h>

struct Position{ float x, y; }; /* pos of pacman's center */
enum class Direction {Up, Down, Left, Right};

class Player
{
	int _BaseSpeed;
	Position _Pos;
	SDL_Event _InputEvent;
	Direction _Direction;
	
public:
	Player();
	~Player();
	void Update();
	Position GetPosition();

private:
	bool IsInputKey(SDL_Event ev);
};
