#include "Player.h"

Player::Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight, AudioManager* _audioManager)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    life = 4;
    parentWidth = _parentWidth;
    parentHeight = _parentHeight;
    speed = 5;
    movableLeft = true;
    movableTop = true;
    movableRight = true;
    movableBottom = true;
    hasToAddTime = false;
    isPlayerMovable = true;
    audioManager = _audioManager;
}

Player::~Player()
{
    delete audioManager;
}

void Player::Move(int moveIndex, Maze& maze)
{
    if (isPlayerMovable) {
        if (moveIndex == 1 && y - speed > 0) {
            CheckMazeCollisions(maze, true, -speed);
            CheckObjectCollisions(maze, true, -speed);
            movableTop ? y -= speed : NULL;
        } else if (moveIndex == 2 && y + speed + height < parentHeight) {
            CheckMazeCollisions(maze, true, speed);
            CheckObjectCollisions(maze, true, speed);
            movableBottom ? y += speed : NULL;
        } else if (moveIndex == 3) {
            CheckMazeCollisions(maze, false, speed);
            CheckObjectCollisions(maze, false, speed);
            maze.MoveWalls(movableLeft ? speed : 0);
            maze.MoveEnemies(movableLeft ? speed : 0);
            maze.MoveBullets(movableLeft ? speed : 0);
            maze.MoveObjects(movableLeft ? speed : 0);
        } else if (moveIndex == 4) {
            CheckMazeCollisions(maze, false, -speed);
            CheckObjectCollisions(maze, false, -speed);
            maze.MoveWalls(movableRight ? -speed : 0);
            maze.MoveEnemies(movableRight ? -speed : 0);
            maze.MoveBullets(movableRight ? -speed : 0);
            maze.MoveObjects(movableRight? -speed : 0);
        }
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

void Player::CheckObjectCollisions(Maze& maze, bool isVerticalMove, int movement)
{
    int pa_x = x;
    int pa_y = y;
    int pb_x = x + width;
    int pb_y = y;
    int pc_x = x + width;
    int pc_y = y + height;
    int pd_x = x;
    int pd_y = y + height;

    for (int x {}; x < 10; ++x) {
        if (maze.objects[x] != nullptr) {
            int oa_x = maze.objects[x]->x;
            int oa_y = maze.objects[x]->y;
            int ob_x = maze.objects[x]->x + maze.objects[x]->width;
            int ob_y = maze.objects[x]->y;
            int oc_x = maze.objects[x]->x + maze.objects[x]->width;
            int oc_y = maze.objects[x]->y + maze.objects[x]->height;
            int od_x = maze.objects[x]->x;
            int od_y = maze.objects[x]->y + maze.objects[x]->height;

            if (CheckSingleObjectCollision(isVerticalMove, movement, pa_x, pa_y, pb_x, pb_y, pc_x, pc_y, pd_x, pd_y, oa_x, oa_y, ob_x, ob_y, oc_x, oc_y, od_x, od_y)) {
                bool catchValue = PlayerCatch(*(maze.objects[x]));
                if (catchValue) {
                    maze.objects[x]->y += 2000;
                };
            }
        } else {
            x = 10;
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

bool Player::CheckSingleObjectCollision(bool isVerticalMove, int movement, int p_a_x, int p_a_y, int p_b_x, int p_b_y, int p_c_x, int p_c_y, int p_d_x, int p_d_y, int o_a_x, int o_a_y, int o_b_x, int o_b_y, int o_c_x, int o_c_y, int o_d_x, int o_d_y)
{
    if (isVerticalMove && movableTop) {
        if (((p_b_x > o_a_x && p_b_x < o_b_x) || (p_a_x < o_b_x && p_a_x > o_a_x)) && ((p_a_y + movement < o_d_y && p_a_y + movement > o_a_y))) {
            return true;
        }
    }

    if (isVerticalMove && movableBottom) {
        if (((p_b_x > o_a_x && p_b_x < o_b_x) || (p_a_x < o_b_x && p_a_x > o_a_x)) && ((p_d_y + movement > o_a_y && p_d_y + movement < o_d_y))) {
            return true;
        }
    }

    if (!isVerticalMove && movableLeft) {
        if ((p_a_x < o_b_x + movement && p_a_x > o_a_x + movement) && ((p_a_y < o_c_y && p_a_y > o_b_y) || (p_d_y < o_c_y && p_d_y > o_b_y))) {
            return true;
        }
    }

    if (!isVerticalMove && movableRight) {
        if ((p_b_x < o_b_x + movement && p_b_x> o_a_x + movement) && ((p_b_y < o_d_y && p_b_y > o_a_y) || (p_c_y > o_a_y && p_c_y < o_d_y))) {
            return true;
        }
    }

    return false;
}

bool Player::CheckBulletCollisions(Bullet* bullet)
{
    int pa_x = x;
    int pa_y = y;
    int pb_x = x + width;
    int pb_y = y;
    int pc_x = x + width;
    int pc_y = y + height;
    int pd_x = x;
    int pd_y = y + height;
    int ba_x = bullet->x;
    int ba_y = bullet->y;
    int bb_x = bullet->x + bullet->width;
    int bb_y = bullet->y;
    int bc_x = bullet->x + bullet->width;
    int bc_y = bullet->y + bullet->height;
    int bd_x = bullet->x;
    int bd_y = bullet->y + bullet->height;

    bool hitTop = ((pb_x >= ba_x && pb_x <= bb_x) || (pa_x <= bb_x && pa_x >= ba_x)) && ((pa_y <= bd_y && pa_y >= ba_y));
    bool hitBottom = ((pb_x >= ba_x && pb_x <= bb_x) || (pa_x <= bb_x && pa_x >= ba_x)) && ((pd_y >= ba_y && pd_y <= bd_y));
    bool hitLeft = (pa_x <= bb_x && pa_x >= ba_x) && ((pa_y <= bc_y && pa_y >= bb_y) || (pd_y <= bc_y && pd_y >= bb_y));
    bool hitRight = (pb_x <= bb_x && pb_x >= ba_x) && ((pb_y <= bd_y && pb_y >= ba_y) || (pc_y >= ba_y && pc_y <= bd_y));
    bool hitCenter = (pa_x <= ba_x && pb_x >= bb_x) && (pd_y >= ba_y && pa_y <= bd_y);

    if (hitTop || hitBottom || hitLeft || hitRight || hitCenter) {
        bullet->Hit();
        PlayerHit();
        return true;
    }

    return false;
}

void Player::PlayerHit()
{
    audioManager->PlaySound(SoundType::HIT);
    life -= 1;
}

bool Player::PlayerCatch(CatchableObject& obj)
{
    if (obj.objectType == ObjectType::LifeObject && life < 4) {
        audioManager->PlaySound(SoundType::CATCH_LIFE);
        life += 1;
        return true;
    } else if (obj.objectType == ObjectType::TimeObject) {
        hasToAddTime = true;
        audioManager->PlaySound(SoundType::CATCH_TIME);
        return true;
    }

    return false;
}

void Player::BlockPlayer()
{
    isPlayerMovable = false;
}