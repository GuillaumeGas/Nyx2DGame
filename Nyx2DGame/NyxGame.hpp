#pragma once

#include "Player.hpp"
#include "Map.hpp"

class NyxGame
{
public:
    NyxGame(const char* mapFilePath);

    void Start();

private:
    Map _map;
    Player _player;
};