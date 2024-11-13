#pragma once

#include <SDL.h>
#include <iostream>
#include "../enums/ButtonTypes.h"
#include "../enums/LevelNumber.h"

class Button {
    public:
        int x, y, textX, textY;
        int width, height;
        SDL_Color textColour, backgroundColour;
        std::string text;
        ButtonType type;

        Button(int _x, int _y, int _textX, int _textY, int _width, int _height, SDL_Color _textColour, SDL_Color _backgroundColour, std::string _text, ButtonType _type);
        LevelNumber CheckIfClicked(int mouseX, int mouseY);
        LevelNumber OnClick();
};