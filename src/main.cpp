#define SDL_MAIN_HANDLED true

#include <SDL.h>
#include "classes/Timer.h"
#include "classes/Window.h"

int main()
{
    SDL_SetMainReady();
    bool isRunning = true;
    Window* window = new Window();
    Timer* timer = new Timer();

    window->LoadTexture("assets/backgrounds/background_one.png");

    while (isRunning) {
        timer->ResetStartLoop();
        window->RenderElements();
        timer->BalanceFPS();
    }

    delete window;
    delete timer;

    return 0;
}