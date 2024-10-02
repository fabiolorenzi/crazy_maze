#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Maze.h"

class Player
{
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        SDL_Rect body;

        Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight);
        void Move(int moveIndex, Maze& maze);
        void CheckMazeCollisions(Maze& maze, bool isVerticalMove, int movement);
    private:
        int parentWidth, parentHeight;
        int speed;
        bool movableLeft, movableRight, movableTop, movableBottom;
        
        void CheckMoveCollision(bool isVerticalMove, int movement, int p_a_x, int p_a_y, int p_b_x, int p_b_y, int p_c_x, int p_c_y, int p_d_x, int p_d_y, int o_a_x, int o_a_y, int o_b_x, int o_b_y, int o_c_x, int o_c_y, int o_d_x, int o_d_y);
};