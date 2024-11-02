#include "CatchableObject.h"

CatchableObject::CatchableObject(int _x, int _y, int _width, int _height, ObjectType _objectType)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    objectType = _objectType;

    if (objectType == ObjectType::LifeObject) {
        r = 0xFF;
        g = 0x00;
        b = 0x00;
        a = 0xFF;
    } else {
        r = 0xFF;
        g = 0xFF;
        b = 0x00;
        a = 0xFF;
    }
}