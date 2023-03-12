#include <fstream>
#include <iostream>
#include <string>

#include "Map.hpp"

void Map::LoadMapFromFile(const char* filePath)
{
    std::ifstream file(filePath);
    int x = 0, y = 0;
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Couldn't open file" << std::endl;
        exit(-1);
    }

    while (std::getline(file, line))
    {
        if (line.length() > GRID_SIZE)
        {
            std::cout << "Invalid map file, too many columns" << std::endl;
            exit(-1);
        }

        for (int i = 0; i < line.length(); i++)
        {
            _grid[y][x] = line[i];
            x++;
        }

        y++;
        x = 0;

        if (y > GRID_SIZE)
        {
            std::cout << "Invalid map file, too many lines" << std::endl;
            exit(-1);
        }
    }
}

void Map::SetPlayerPosition(Position pos)
{
    _grid[_playerPosition.y][_playerPosition.x] = '0';

    _playerPosition = pos;

    _grid[_playerPosition.y][_playerPosition.x] = 'P';
}

void Map::Display()
{
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            std::cout << _grid[y][x];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}