#include "Button.h"

Button::Button(int _x, int _y, int _textX, int _textY, int _width, int _height, SDL_Color _textColour, SDL_Color _backgroundColour, std::string _text)
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
}

void Button::CheckIfClicked(int mouseX, int mouseY)
{
    if ((mouseX > x && mouseX < x + width) && (mouseY > y && mouseY < y + height)) {
        std::cout << "clicked inside" << std::endl;
    } else {
        std::cout << "clicked outside" << std::endl;
    }
}