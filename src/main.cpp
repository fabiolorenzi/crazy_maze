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

    SDL_Texture* backgroundTexture = window->LoadTexture("assets/backgrounds/background_one.png");

    while (isRunning) {
        timer->ResetStartLoop();
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        window->RenderElements(backgroundTexture);
        timer->BalanceFPS();
    }   
    
    delete backgroundTexture;
    delete window;
    delete timer;

    return 0;
}