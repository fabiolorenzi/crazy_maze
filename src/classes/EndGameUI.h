#pragma once

#include <SDL.h>
#include <iostream>
#include "Button.h"
#include "../enums/ButtonTypes.h"
#include "../enums/EndGameResults.h"

class EndGameUI {
    public:
        int x, y;
        int width, height;
        SDL_Color textColour;
        EndGameResult result;
        std::string message;
        Button* restartButton;
        Button* menuButton;

        EndGameUI(int _x, int _y, int _width, int _height, EndGameResult _result);
        ~EndGameUI();
        void CheckIfButtonsAreClicked(int mouseX, int mouseY);
};