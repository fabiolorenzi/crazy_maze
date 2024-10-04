#include "Bullet.h"

Bullet::Bullet(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _speed)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    speed = _speed;
}

void Bullet::Move()
{
    y -= speed;
}