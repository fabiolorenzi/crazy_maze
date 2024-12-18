#include "KeysManager.h"

void LoopEvent(bool& isRunning, Window*& window, EndGameResult result)
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            isRunning = false;
        } else if (e.type == SDL_KEYDOWN) {
            window->GetPlayerFromLevel().UpdateMoveIndex(KeyDownManager(e));
        } else if (e.type == SDL_KEYUP) {
            window->GetPlayerFromLevel().UpdateMoveIndex(0);
        } else if (e.type == SDL_MOUSEBUTTONUP) {
            if (result != EndGameResult::Waiting) {
                LevelNumber newLevel = window->GetEndGameUIFromLevel().CheckIfButtonsAreClicked(e.button.x, e.button.y);
                if (newLevel != LevelNumber::None) {
                    window->SetLevel(newLevel);
                }
            } else if (window->GetLevel().levelNumber == LevelNumber::Menu || window->GetLevel().levelNumber == LevelNumber::LevelsMenu) {
                LevelNumber newLevel = window->GetMenuUIFromLevel().CheckIfButtonsAreClicked(e.button.x, e.button.y);
                if (newLevel == LevelNumber::Quit) {
                    window->quit = true;
                } else if (newLevel != LevelNumber::None) {
                    window->SetLevel(newLevel);
                }
            }
        }
    }
}

int KeyDownManager(SDL_Event e)
{
    switch (e.key.keysym.sym) {
        case SDLK_UP:
            return KeyCodes::KEY_PRESS_SURFACE_UP;
            break;
        case SDLK_DOWN:
            return KeyCodes::KEY_PRESS_SURFACE_DOWN;
            break;
        case SDLK_LEFT:
            return KeyCodes::KEY_PRESS_SURFACE_LEFT;
            break;
        case SDLK_RIGHT:
            return KeyCodes::KEY_PRESS_SURFACE_RIGHT;
            break;
        default:
            return KeyCodes::KEY_PRESS_SURFACE_DEFAULT;
            break;
    }
}