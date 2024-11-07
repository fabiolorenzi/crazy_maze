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
        message = "You have won";
    } else if (result == EndGameResult::LifeEnd) {
        textColour = {255, 0, 0, 255};
        message = "You are dead";
    } else if (result == EndGameResult::TimeEnd) {
        textColour = {255, 0, 0, 255};
        message = "Time finished";
    }

    restartButton = new Button(width / 2 - 120, height / 2, width / 2 - 100, height / 2, width, height, {255, 255, 255, 255}, {0, 0, 0, 255}, "Restart");
    menuButton = new Button(width / 2 - 120, height / 2 + 80, width / 2 - 100, height / 2 + 80, width, height, {255, 255, 255, 255}, {0, 0, 0, 255}, "Menu");
}

EndGameUI::~EndGameUI()
{
    delete restartButton;
    delete menuButton;
}