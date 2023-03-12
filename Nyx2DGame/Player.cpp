#include <iostream>

#include "Player.hpp"
#include "Map.hpp"

Player::Player() : _pos(0, 0), _dir(Direction::DOWN) {}

void Player::Turn(Direction dir)
{
    _dir = dir;
}

void Player::Move()
{
	switch (_dir)
	{
	case Player::UP:
		if (_pos.y > 0)
			_pos.y--;
		break;
	case Player::DOWN:
		if (_pos.y < GRID_SIZE - 1)
			_pos.y++;
		break;
	case Player::RIGHT:
		if (_pos.x < GRID_SIZE - 1)
			_pos.x++;
		break;
	case Player::LEFT:
		if(_pos.x > 0)
			_pos.x--;
		break;
	default:
		std::cout << "Invalid direction" << std::endl;
		break;
	}
}

void Player::Shoot()
{
	// TODO
}

void Player::Build()
{
	// TODO
}

Position Player::GetPosition() const
{
	return _pos;
}