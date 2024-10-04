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
}

Enemy::~Enemy()
{
    for (Bullet* bullet : bullets) {
        if (bullet) delete bullet;
    }
}

int Enemy::Shoot(int counter)
{
    if (counter % shootDelayDiv == 0 && x >= -50 && x <= parentWidth) {
        for (int x {}; x < 4; ++x) {
            if (bullets[x] == nullptr) {
                bullets[x] = new Bullet(x + (width / 2) - 10, y, 20, 20, 0xFF, 0xFF, 0x00, 0xFF);
                return 0;
            }
        }
    }
    return 0;
}

void Enemy::DeleteBullet(int index)
{
    delete bullets[x];
}