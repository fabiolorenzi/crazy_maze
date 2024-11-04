#pragma once

#include <SDL.h>

class EndGameUI {
    public:
        int x, y;
        int width, height;

        EndGameUI(int _x, int _y, int _width, int _height);
};