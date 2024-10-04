#pragma once

#include <SDL.h>
#include <iostream>
#include "Enemy.h"
#include "Wall.h"
#include "../enums/LevelNumber.h"
#include "../functions/LevelElementsManager.h"

class Maze
{
    public:
        Wall* walls[100] {nullptr};
        Enemy* enemies[20] {nullptr};

        Maze(LevelNumber _levelNumber, int parentWidth, int parentHeight);
        ~Maze();
        void MoveWalls(int movement);
        void MoveEnemies(int movement);
        void MoveBullets(int movement);
        void TriggerEnemies(int time);
    private:
        LevelNumber levelNumber;
        int width, height;
};