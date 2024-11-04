#include "EndGameUI.h"

EndGameUI::EndGameUI(int _x, int _y, int _width, int _height, EndGameResult _result)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    result = _result;

    if (result == EndGameResult::Victory) {
        textColour = {0, 255, 0, 255};
        message = "You won";
    } else if (result == EndGameResult::LifeEnd) {
        textColour = {255, 0, 0, 255};
        message = "You are dead";
    } else if (result == EndGameResult::TimeEnd) {
        textColour = {255, 0, 0, 255};
        message = "The time is finished";
    }
}