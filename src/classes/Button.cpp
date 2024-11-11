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
            newLevel = MenuButtonFunction();
            break;
        case ButtonType::RESTART_BUTTON:
            newLevel = RestartButtonFunction();
            break;
    }

    return newLevel;
}

LevelNumber Button::MenuButtonFunction()
{
    return LevelNumber::Menu;
}

LevelNumber Button::RestartButtonFunction()
{
    return LevelNumber::LevelOne;
}