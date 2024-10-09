#pragma once

#include <SDL.h>
#include "../classes/Enemy.h"
#include "../classes/Wall.h"
#include "../enums/LevelNumber.h"

unsigned int SetLevelInitialTimer(LevelNumber levelNumber);
void PopulateWallsInMazeArray(LevelNumber levelNumber, Wall* wallsArray[100], int width, int height);
void PopulateEnemiesInMazeArray(LevelNumber levelNumber, Enemy* enemiesArray[20], int width, int height);