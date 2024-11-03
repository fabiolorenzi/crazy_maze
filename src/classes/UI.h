#pragma once

#include <SDL.h>

class UI {
    public:
        int x, y;
        int width, height;
        int life;
        int time;
        
        UI(int _x, int _y, int _width, int _height, int _life, int _time);
        void UpdateLife(int newValue);
        void UpdateTime(int newValue);
        void RemoveUI();
};