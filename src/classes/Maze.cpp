#include "Maze.h"

Maze::Maze(int parentWidth, int parentHeight)
{
    width = parentWidth;
    height = parentHeight;

    walls[0] = new Wall(0, height - 10, width, 10, 0x8B, 0x45, 0x13, 0x00);
    walls[1] = new Wall(0, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
    walls[2] = new Wall(width - 10, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
}

Maze::~Maze()
{
    for (Wall* wall : walls) {
        delete wall;
    }
}