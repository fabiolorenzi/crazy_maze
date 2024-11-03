#pragma once

#include <SDL.h>

class GameUI {
    public:
        int x, y;
        int width, height;
        int life;
        int time;
        
        GameUI(int _x, int _y, int _width, int _height, int _life, int _time);
        void UpdateLife(int newValue);
        void UpdateTime(int newValue);
        void RemoveUI();
};