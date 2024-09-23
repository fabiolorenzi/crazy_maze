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
    verticalSpeed = 4;
}

void Player::Move(int moveIndex)
{
    if (moveIndex == 1 && y - verticalSpeed > 0) {
        y -= verticalSpeed;
    } else if (moveIndex == 2 && y + verticalSpeed + height < parentHeight) {
        y += verticalSpeed;
    }
}