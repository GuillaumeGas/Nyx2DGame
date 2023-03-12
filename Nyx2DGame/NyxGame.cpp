#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#include "NyxGame.hpp"

#include "Nyx/compilo/Compilo.hpp"

NyxGame::NyxGame(const char* mapFilePath)
{
	_map.LoadMapFromFile(mapFilePath);
}

void NyxGame::Start()
{
	int value = 1;
	while (value)
	{
		nyx::Compilo c("testmap.nx");
		value = c.compile();

		if (value > 0)
		{
			if (value == 8)
			{
				_player.Turn(Player::Direction::UP);
			}
			else if (value == 2)
			{
				_player.Turn(Player::Direction::DOWN);
			}
			else if (value == 6)
			{
				_player.Turn(Player::Direction::RIGHT);
			}
			else if (value == 4)
			{
				_player.Turn(Player::Direction::LEFT);
			}
			else if (value == 1)
			{
				_player.Move();
			}
		}

		_map.SetPlayerPosition(_player.GetPosition());
		_map.Display();

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}