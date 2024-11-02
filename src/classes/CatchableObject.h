#pragma once

#include <SDL.h>
#include <iostream>
#include "../enums/ObjectType.h"

class CatchableObject {
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        ObjectType objectType;

        CatchableObject(int _x, int _y, int _width, int _height, ObjectType _objectType);
};