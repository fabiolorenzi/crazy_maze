#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Renderer
{
    public:
        SDL_Renderer* renderer;
        Renderer(SDL_Window* window);
        ~Renderer();
        void Reset();
};