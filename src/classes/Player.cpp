#include "Player.h"

Player::Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    parentWidth = _parentWidth;
    parentHeight = _parentHeight;
    speed = 5;
}

void Player::Move(int moveIndex, Maze& maze)
{
    if (moveIndex == 1 && y - speed > 0) {
        y -= speed;
    } else if (moveIndex == 2 && y + speed + height < parentHeight) {
        y += speed;
    } else if (moveIndex == 3) {
        maze.MoveWalls(speed);
    } else if (moveIndex == 4) {
        maze.MoveWalls(-speed);
    }
}