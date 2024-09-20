#pragma once

#include <SDL.h>
#include <iostream>
#include "Wall.h"

class Maze
{
    public:
        Wall* walls[3];

        Maze(int parentWidth, int parentHeight);
        ~Maze();
    private:
        int width, height;
};