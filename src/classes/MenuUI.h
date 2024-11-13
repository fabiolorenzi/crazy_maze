#pragma once

#include <SDL.h>
#include <iostream>
#include "Button.h"
#include "../enums/ButtonTypes.h"
#include "../enums/LevelNumber.h"

class MenuUI
{
    public:
        int x, y;
        int width, height;
        bool isShowingLevels;
        LevelNumber levelNumber;
        Button* playButton;
        Button* backButton;
        Button* levelOneButton;
        Button* levelTwoButton;
        Button* levelThreeButton;
        Button* quitButton;

        MenuUI(int _x, int _y, int _width, int _height, LevelNumber _levelNumber);
        ~MenuUI();
        LevelNumber CheckIfButtonsAreClicked(int mouseX, int mouseY);
};