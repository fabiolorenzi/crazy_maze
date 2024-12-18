#pragma once

#include <SDL.h>
#include "../classes/CatchableObject.h"
#include "../classes/Enemy.h"
#include "../classes/Wall.h"
#include "../enums/LevelNumber.h"

unsigned int SetLevelInitialTimer(LevelNumber levelNumber);
void PopulateWallsInMazeArray(LevelNumber levelNumber, Wall* wallsArray[50], int width, int height);
void PopulateEnemiesInMazeArray(LevelNumber levelNumber, Enemy* enemiesArray[10], int width, int height);
void PopulateObjectsInMazeArray(LevelNumber levelNumber, CatchableObject* objectsArray[5], int width, int height);