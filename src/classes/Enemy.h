#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Bullet.h"

class Enemy
{
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        Bullet* bullets[4] {nullptr};

        Enemy(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight, int _speed, int _shootDelay);
        ~Enemy();
        int Shoot(int counter);
        void DeleteBullet(int index);
    private:
        int parentWidth, parentHeight;
        int speed, shootDelayDiv;
};