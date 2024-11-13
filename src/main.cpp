#define SDL_MAIN_HANDLED true

#include <SDL.h>
#include "classes/Timer.h"
#include "classes/Window.h"
#include "functions/KeysManager.h"

int main()
{
    SDL_SetMainReady();
    bool isRunning = true;
    Window* window = new Window();
    Timer* timer = new Timer();

    while (isRunning) {
        timer->ResetStartLoop();

        LoopEvent(isRunning, window, window->gameResult);

        window->RenderElements();
        timer->BalanceFPS();
        
        if (window->quit) {
            isRunning = false;
        }
    }   
    
    delete window;
    delete timer;

    return 0;
}