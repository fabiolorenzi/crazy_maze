#include "Player.h"

Player::Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    parentWidth = _parentWidth;
    parentHeight = _parentHeight;
    speed = 5;
    movableLeft = true;
    movableTop = true;
    movableRight = true;
    movableBottom = true;
}

void Player::Move(int moveIndex, Maze& maze)
{
    if (moveIndex == 1 && y - speed > 0) {
        CheckMazeCollisions(maze, true, -speed);
        movableTop ? y -= speed : NULL;
    } else if (moveIndex == 2 && y + speed + height < parentHeight) {
        CheckMazeCollisions(maze, true, speed);
        movableBottom ? y += speed : NULL;
    } else if (moveIndex == 3) {
        CheckMazeCollisions(maze, false, speed);
        maze.MoveWalls(movableLeft ? speed : 0);
        maze.MoveEnemies(movableLeft ? speed : 0);
        maze.MoveBullets(movableLeft ? speed : 0);
    } else if (moveIndex == 4) {
        CheckMazeCollisions(maze, false, -speed);
        maze.MoveWalls(movableRight ? -speed : 0);
        maze.MoveEnemies(movableRight ? -speed : 0);
        maze.MoveBullets(movableRight ? -speed : 0);
    }
}

void Player::CheckMazeCollisions(Maze& maze, bool isVerticalMove, int movement)
{
    movableLeft = true;
    movableTop = true;
    movableRight = true;
    movableBottom = true;

    int pa_x = x;
    int pa_y = y;
    int pb_x = x + width;
    int pb_y = y;
    int pc_x = x + width;
    int pc_y = y + height;
    int pd_x = x;
    int pd_y = y + height;

    for (int x {}; x < 100; ++x) {
        if (maze.walls[x] != nullptr) {
            int wa_x = maze.walls[x]->x;
            int wa_y = maze.walls[x]->y;
            int wb_x = maze.walls[x]->x + maze.walls[x]->width;
            int wb_y = maze.walls[x]->y;
            int wc_x = maze.walls[x]->x + maze.walls[x]->width;
            int wc_y = maze.walls[x]->y + maze.walls[x]->height;
            int wd_x = maze.walls[x]->x;
            int wd_y = maze.walls[x]->y + maze.walls[x]->height;

            CheckMoveCollision(isVerticalMove, movement, pa_x, pa_y, pb_x, pb_y, pc_x, pc_y, pd_x, pd_y, wa_x, wa_y, wb_x, wb_y, wc_x, wc_y, wd_x, wd_y);
        } else {
            x = 100;
        }
    }
}

void Player::CheckMoveCollision(bool isVerticalMove, int movement, int p_a_x, int p_a_y, int p_b_x, int p_b_y, int p_c_x, int p_c_y, int p_d_x, int p_d_y, int o_a_x, int o_a_y, int o_b_x, int o_b_y, int o_c_x, int o_c_y, int o_d_x, int o_d_y)
{
    if (isVerticalMove && movableTop) {
        if (((p_b_x > o_a_x && p_b_x < o_b_x) || (p_a_x < o_b_x && p_a_x > o_a_x)) && ((p_a_y + movement < o_d_y && p_a_y + movement > o_a_y))) {
            movableTop = false;
        }
    }

    if (isVerticalMove && movableBottom) {
        if (((p_b_x > o_a_x && p_b_x < o_b_x) || (p_a_x < o_b_x && p_a_x > o_a_x)) && ((p_d_y + movement > o_a_y && p_d_y + movement < o_d_y))) {
            movableBottom = false;
        }
    }

    if (!isVerticalMove && movableLeft) {
        if ((p_a_x < o_b_x + movement && p_a_x > o_a_x + movement) && ((p_a_y < o_c_y && p_a_y > o_b_y) || (p_d_y < o_c_y && p_d_y > o_b_y))) {
            movableLeft = false;
        }
    }

    if (!isVerticalMove && movableRight) {
        if ((p_b_x < o_b_x + movement && p_b_x> o_a_x + movement) && ((p_b_y < o_d_y && p_b_y > o_a_y) || (p_c_y > o_a_y && p_c_y < o_d_y))) {
            movableRight = false;
        }
    }
}