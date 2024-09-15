#define SDL_MAIN_HANDLED true

#include <SDL.h>
#include "classes/Window.h"

int main()
{
    SDL_SetMainReady();
    bool isRunning = true;
    Window* window = new Window();
    window->LoadMedia("assets/backgrounds/background_one.png");

    while (isRunning) {
        window->RenderElements();
    }

    delete window;

    return 0;
}