#include <iostream>

#include "NyxGame.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Missing map file" << std::endl;
        return -1;
    }

    NyxGame game(argv[1]);
    game.Start();

    return 0;
}