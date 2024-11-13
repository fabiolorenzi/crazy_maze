#include "MenuUI.h"

MenuUI::MenuUI(int _x, int _y, int _width, int _height, LevelNumber _levelNumber)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    isShowingLevels = false;
    levelNumber = _levelNumber;

    if (levelNumber == LevelNumber::Menu) {
        playButton = new Button(width / 2 - 100, height / 2, width / 2 - 100, height / 2, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Play", ButtonType::LEVELS_MENU_BUTTON);
        quitButton = new Button(width / 2 - 100, height / 2 + 80, width / 2 - 100, height / 2 + 80, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Quit", ButtonType::QUIT_BUTTON);
        backButton = nullptr;
        levelOneButton = nullptr;
        levelTwoButton = nullptr;
        levelThreeButton = nullptr;
    } else if (levelNumber == LevelNumber::LevelsMenu) {
        playButton = nullptr;
        quitButton = nullptr;
        backButton = new Button(width / 2 - 100, height / 2, width / 2 - 100, height / 2, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Back", ButtonType::MENU_BUTTON);
        levelOneButton = new Button(width / 2 - 100, height / 2 + 80, width / 2 - 100, height / 2 + 80, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Lv 1", ButtonType::LEVEL_ONE_BUTTON);
        levelTwoButton = new Button(width / 2 - 100, height / 2 + 160, width / 2 - 100, height / 2 + 80, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Lv 2", ButtonType::LEVEL_TWO_BUTTON);
        levelThreeButton = new Button(width / 2 - 100, height / 2 + 240, width / 2 - 100, height / 2 + 80, 200, 40, {255, 255, 255, 255}, {33, 33, 33, 255}, "Lv 3", ButtonType::LEVEL_THREE_BUTTON);
    }
}

MenuUI::~MenuUI()
{
    if (playButton != nullptr) delete playButton;
    if (backButton != nullptr) delete backButton;
    if (quitButton != nullptr) delete quitButton;
    if (levelOneButton != nullptr) delete levelOneButton;
    if (levelTwoButton != nullptr) delete levelTwoButton;
    if (levelThreeButton != nullptr) delete levelThreeButton;
}

LevelNumber MenuUI::CheckIfButtonsAreClicked(int mouseX, int mouseY)
{
    if (levelNumber == LevelNumber::Menu) {
        if (playButton->CheckIfClicked(mouseX, mouseY) != LevelNumber::None) {
            return playButton->CheckIfClicked(mouseX, mouseY);
        } else if (quitButton->CheckIfClicked(mouseX, mouseY) != LevelNumber::None) {
            return quitButton->CheckIfClicked(mouseX, mouseY);
        }
    } else if (levelNumber == LevelNumber::LevelsMenu) {
        if (levelOneButton->CheckIfClicked(mouseX, mouseY) != LevelNumber::None) {
            return levelOneButton->CheckIfClicked(mouseX, mouseY);
        } else if (levelTwoButton->CheckIfClicked(mouseX, mouseY) != LevelNumber::None) {
            return levelTwoButton->CheckIfClicked(mouseX, mouseY);
        } else if (levelThreeButton->CheckIfClicked(mouseX, mouseY) != LevelNumber::None) {
            return levelThreeButton->CheckIfClicked(mouseX, mouseY);
        } else if (backButton->CheckIfClicked(mouseX, mouseY) != LevelNumber::None) {
            return backButton->CheckIfClicked(mouseX, mouseY);
        }
    }

    return LevelNumber::None;
}