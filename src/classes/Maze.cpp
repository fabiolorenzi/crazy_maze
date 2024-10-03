#include "Maze.h"

Maze::Maze(LevelNumber _levelNumber, int parentWidth, int parentHeight)
{
    levelNumber = _levelNumber;
    width = parentWidth;
    height = parentHeight;

    PopulateWallsInMazeArray(levelNumber, walls, width, height);
    PopulateEnemiesInMazeArray(levelNumber, enemies, width, height);
}

Maze::~Maze()
{
    for (Enemy* enemy : enemies) {
        if (enemy) {
            delete enemy;
        }
    }

    for (Wall* wall : walls) {
        if (wall) {
            delete wall;
        }
    }
}

void Maze::MoveWalls(int movement)
{
    if (movement != 0) {
        for (Wall* wall : walls) {
            wall ? wall->x += movement : NULL;
        }
    }
}

void Maze::MoveEnemies(int movement)
{
    if (movement != 0) {
        for (Enemy* enemy : enemies) {
            enemy ? enemy->x += movement : NULL;
        }
    }
}

void Maze::TriggerEnemies(int time)
{
    for (Enemy* enemy : enemies) {
        if (enemy) enemy->Shoot(time);
    }
}