#include "Player.hpp"

void Player::Update()
{
	SDL_PollEvent(&_InputEvent);
	if (_InputEvent.type == SDL_KEYDOWN && IsInputKey(_InputEvent))
	{
		switch (_InputEvent.key.keysym.sym) 
		{
		case (SDLK_UP):
			_Direction = Direction::Up;
			break;
		case (SDLK_DOWN):
			_Direction = Direction::Down;
			break;
		case (SDLK_LEFT):
			_Direction = Direction::Left;
			break;
		case (SDLK_RIGHT):
			_Direction = Direction::Right;
			break;
		}
	}

	// TODO obvi not doing bound detection or collisions. need to implement it before level.
	switch (_Direction)
	{
	case (Direction::Up):
		_Pos.y -= (float)_BaseSpeed / 60;
		break;
	case (Direction::Down):
		_Pos.y += (float)_BaseSpeed / 60;
		break;
	case (Direction::Left):
		_Pos.x -= (float)_BaseSpeed / 60;
		break;
	case (Direction::Right):
		_Pos.x += (float)_BaseSpeed / 60;
		break;
	}
}

Position Player::GetPosition()
{
	Position pos = { _Pos.x, _Pos.y };
	return pos;
}

Player::Player()
{
	_BaseSpeed = 88; // px per sec
	_Pos = { 100, 100 };
	_Direction = Direction::Left;
}

bool Player::IsInputKey(SDL_Event ev)
{
	if (ev.key.keysym.sym == SDLK_UP ||
		ev.key.keysym.sym == SDLK_DOWN ||
		ev.key.keysym.sym == SDLK_RIGHT ||
		ev.key.keysym.sym == SDLK_LEFT)
		return true;
	else
		return false;
}
