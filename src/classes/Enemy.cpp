#include "Enemy.h"

Enemy::Enemy(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _parentWidth, int _parentHeight, int _speed, int _shootSpeed)
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
    shootSpeed = _shootSpeed;
    bullet = nullptr;
}

Enemy::~Enemy()
{
    if (bullet) delete bullet;
}

void Enemy::Shoot()
{
    if (bullet == nullptr && x >= -50 && x <= parentWidth) {
        bullet = new Bullet(x + (width / 2) - 10, y, 20, 20, 0xFF, 0xFF, 0x00, 0xFF, shootSpeed);
    }
}

void Enemy::DeleteBullet()
{
    delete bullet;
    bullet = nullptr;
}