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
        Bullet* bullet;

        Enemy(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight, unsigned int _shootSpeed);
        ~Enemy();
        void Shoot();
        void DeleteBullet();
    private:
        int parentWidth, parentHeight;
        unsigned int shootSpeed;
};