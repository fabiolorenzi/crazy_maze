#pragma once

#include <SDL.h>
#include <iostream>
#include "Renderer.h"

class Level
{
    public:
        SDL_Texture* background;

        Level(SDL_Surface* pScreenSurface, Renderer* pRenderer, std::string backgroundPath);
        ~Level();
    private:
        SDL_Surface* parentScreenSurface;
        Renderer* parentRenderer;

        SDL_Texture* LoadBackground(std::string texturePath);
        SDL_Surface* LoadSurface(std::string imagePath);
};