#include "LevelElementsManager.h"

void PopulateWallsInMazeArray(LevelNumber levelNumber, Wall* wallsArray[100], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        wallsArray[0] = new Wall(0, height - 10, width, 10, 0x8B, 0x45, 0x13, 0x00);
        wallsArray[1] = new Wall(0, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(width - 10, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(0, 50, width, 10, 0x8B, 0x45, 0x13, 0x00);
    }
}