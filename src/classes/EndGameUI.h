#pragma once

#include <SDL.h>
#include <iostream>
#include "../enums/EndGameResults.h"

class EndGameUI {
    public:
        int x, y;
        int width, height;
        SDL_Color textColour;
        EndGameResult result;
        std::string message;

        EndGameUI(int _x, int _y, int _width, int _height, EndGameResult _result);
};