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

    restartButton = new Button(width / 2 - 100, height / 2, width / 2 - 100, height / 2, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Restart", ButtonType::RESTART_BUTTON);
    menuButton = new Button(width / 2 - 100, height / 2 + 80, width / 2 - 100, height / 2 + 80, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Menu", ButtonType::MENU_BUTTON);
}

EndGameUI::~EndGameUI()
{
    delete restartButton;
    delete menuButton;
}

void EndGameUI::CheckIfButtonsAreClicked(int mouseX, int mouseY)
{
    restartButton->CheckIfClicked(mouseX, mouseY);
    menuButton->CheckIfClicked(mouseX, mouseY);
}