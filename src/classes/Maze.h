#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "Wall.h"

class Maze
{
    public:
        std::vector<Wall*>* walls;

        Maze(int parentWidth, int parentHeight);
        ~Maze();
    private:
        int width, height;
};