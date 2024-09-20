#pragma once

#include <SDL.h>
#include "../classes/Wall.h"
#include "../enums/LevelNumber.h"

void PopulateWallsInMazeArray(LevelNumber levelNumber, Wall* wallsArray[100], int width, int height);