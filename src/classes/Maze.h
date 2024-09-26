#pragma once

#include <SDL.h>
#include <iostream>
#include "Wall.h"
#include "../enums/LevelNumber.h"
#include "../functions/LevelElementsManager.h"

class Maze
{
    public:
        Wall* walls[100] {nullptr};

        Maze(LevelNumber _levelNumber, int parentWidth, int parentHeight);
        ~Maze();
        void MoveWalls(int movement);
    private:
        LevelNumber levelNumber;
        int width, height;
};