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

void Button::CheckIfClicked(int mouseX, int mouseY)
{
    if ((mouseX > x && mouseX < x + width) && (mouseY > y && mouseY < y + height)) {
        OnClick();
    }
}

void Button::OnClick()
{
    switch (type) {
        case ButtonType::MENU_BUTTON:
            MenuButtonFunction();
            break;
        case ButtonType::RESTART_BUTTON:
            RestartButtonFunction();
            break;
    }
}

void Button::MenuButtonFunction()
{
    std::cout << "menu button" << std::endl;
}

void Button::RestartButtonFunction()
{
    std::cout << "restart button" << std::endl;
}