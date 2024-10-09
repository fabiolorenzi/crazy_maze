#pragma once

#include <SDL.h>

class Bullet
{
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        bool hasHit;

        Bullet(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _speed);
        void Move();
        void Hit();
    private:
        int speed;
};