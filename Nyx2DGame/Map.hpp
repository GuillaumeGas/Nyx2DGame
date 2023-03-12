#pragma once

#include "Player.hpp"

#define GRID_SIZE 10

class Map
{
public:
    void LoadMapFromFile(const char* filePath);

    void SetPlayerPosition(Position pos);
    void Display();

private:
    char _grid[GRID_SIZE][GRID_SIZE];

    Position _playerPosition;
};