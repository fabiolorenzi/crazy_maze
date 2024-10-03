#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>

class Enemy
{
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        SDL_Rect body;

        Enemy(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight, int _speed, int _shootDelay);
        void Shoot(int counter);
    private:
        int parentWidth, parentHeight;
        int speed, shootDelayDiv;
};