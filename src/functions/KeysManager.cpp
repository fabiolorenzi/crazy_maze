#include "KeysManager.h"

void LoopEvent(bool& isRunning, Window*& window, EndGameResult result)
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            isRunning = false;
        } else if (e.type == SDL_KEYDOWN) {
            window->GetPlayerFromLevel().Move(KeyDownManager(e), window->GetMazeFromLevel());
        } else if (e.type == SDL_KEYUP) {
            window->GetPlayerFromLevel().Move(0, window->GetMazeFromLevel());
        } else if (e.type == SDL_MOUSEBUTTONUP) {
            std::cout << "has clicked" << std::endl;
            std::cout << "x: " << e.button.x << std::endl;
            std::cout << "y: " << e.button.y << std::endl;
            std::cout << "result: " << window->gameResult << std::endl;
            if (result != EndGameResult::Waiting) {
                window->GetEndGameUIFromLevel().CheckIfButtonsAreClicked(e.button.x, e.button.y);
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