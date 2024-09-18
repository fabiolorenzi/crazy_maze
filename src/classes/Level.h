#pragma once

#include <SDL.h>
#include <iostream>
#include "Player.h"
#include "Renderer.h"
#include "../enums/LevelNumber.h"

class Level
{
    public:
        LevelNumber levelNumber;
        SDL_Texture* background;

        Level(SDL_Surface* pScreenSurface, Renderer* pRenderer, LevelNumber levelNumber, int parentWidth, int parentHeight);
        ~Level();
        void RenderLevel();
    private:
        int width, height;
        Player* player;
        SDL_Surface* parentScreenSurface;
        Renderer* parentRenderer;

        void SetBackground(LevelNumber level);
        SDL_Texture* LoadBackground(std::string texturePath);
        SDL_Surface* LoadSurface(std::string imagePath);
};