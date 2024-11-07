#include "LevelElementsManager.h"

unsigned int SetLevelInitialTimer(LevelNumber levelNumber)
{
    if (levelNumber == LevelNumber::LevelOne) {
        return 5;
    }
    
    return 0;
}

void PopulateWallsInMazeArray(LevelNumber levelNumber, Wall* wallsArray[100], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        wallsArray[0] = new Wall(0, height - 10, width, 10, 0x8B, 0x45, 0x13, 0x00);
        wallsArray[1] = new Wall(0, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(width - 10, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(0, 50, width / 2, 10, 0x8B, 0x45, 0x13, 0x00);
    }
}

void PopulateEnemiesInMazeArray(LevelNumber levelNumber, Enemy* enemiesArray[20], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        enemiesArray[0] = new Enemy(width - 100, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[1] = new Enemy(50, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
    }
}

void PopulateObjectsInMazeArray(LevelNumber levelNumber, CatchableObject* objectsArray[10], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        objectsArray[0] = new CatchableObject(200, height - 150, 40, 40, ObjectType::LifeObject);
        objectsArray[1] = new CatchableObject(width - 200, height - 150, 40, 40, ObjectType::TimeObject);
    }
}