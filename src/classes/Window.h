#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Level.h"
#include "Renderer.h"

class Window
{
    public:
        SDL_Surface* gScreenSurface;
        Renderer* gRenderer;
        Window();
        ~Window();
        void RenderElements();
    private:
        int width;
        int height;
        SDL_Window* gWindow;
        SDL_Surface* gStretched;
        Level* level;

        int Init();
};