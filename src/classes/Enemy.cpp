#include "Enemy.h"

Enemy::Enemy(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight, int _speed, int _shootDelayDiv)
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
    speed = speed;
    shootDelayDiv = _shootDelayDiv;
    isAlive = true;

    // LoopManager();
}

Enemy::~Enemy()
{
    isAlive = false;
}

void Enemy::LoopManager()
{
    while (isAlive) {
        std::cout << "shoot" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(5000 / shootDelayDiv)));
    }
}