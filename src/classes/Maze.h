#pragma once

#include <SDL.h>
#include <iostream>
#include "CatchableObject.h"
#include "Enemy.h"
#include "Wall.h"
#include "../enums/LevelNumber.h"
#include "../functions/LevelElementsManager.h"

class Maze
{
    public:
        Wall* walls[50] {nullptr};
        Enemy* enemies[10] {nullptr};
        CatchableObject* objects[5] {nullptr};

        Maze(LevelNumber _levelNumber, int parentWidth, int parentHeight);
        ~Maze();
        void MoveWalls(int movement);
        void MoveEnemies(int movement);
        void MoveBullets(int movement);
        void MoveObjects(int movement);
        void TriggerEnemies(int time);
    private:
        LevelNumber levelNumber;
        int width, height;
};