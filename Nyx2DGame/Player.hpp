#pragma once

struct Position
{
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}

    int x;
    int y;
};

class Player
{
public:
    Player();

    enum Direction { UP, DOWN, RIGHT, LEFT };

    void Turn(Direction dir);
    void Move();
    void Shoot();
    void Build();

    Position GetPosition() const;

private:
    Position _pos;
    Direction _dir;
};