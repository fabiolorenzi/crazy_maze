#include "Button.h"

Button::Button(int _x, int _y, int _textX, int _textY, int _width, int _height, SDL_Color _textColour, SDL_Color _backgroundColour, std::string _text, ButtonType _type)
{
    x = _x;
    y = _y;
    textX = _textX;
    textY = _textY;
    width = _width;
    height = _height;
    textColour = _textColour;
    backgroundColour = _backgroundColour;
    text = _text;
    type = _type;
}

LevelNumber Button::CheckIfClicked(int mouseX, int mouseY)
{
    if ((mouseX > x && mouseX < x + width) && (mouseY > y && mouseY < y + height)) {
        return OnClick();
    }

    return LevelNumber::None;
}

LevelNumber Button::OnClick()
{
    LevelNumber newLevel = LevelNumber::None;
    switch (type) {
        case ButtonType::MENU_BUTTON:
            newLevel = LevelNumber::Menu;
            break;
        case ButtonType::LEVELS_MENU_BUTTON:
            newLevel = LevelNumber::LevelsMenu;
            break;
        case ButtonType::RESTART_BUTTON:
            newLevel = LevelNumber::LevelOne;
            break;
        case ButtonType::LEVEL_ONE_BUTTON:
            newLevel = LevelNumber::LevelOne;
            break;
        case ButtonType::LEVEL_TWO_BUTTON:
            newLevel = LevelNumber::LevelTwo;
            break;
        case ButtonType::LEVEL_THREE_BUTTON:
            newLevel = LevelNumber::LevelThree;
            break;
        case ButtonType::QUIT_BUTTON:
            newLevel = LevelNumber::Quit;
            break;
    }

    return newLevel;
}