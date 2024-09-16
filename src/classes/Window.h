#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Renderer.h"

class Window
{
    public:
        Window();
        ~Window();
        SDL_Texture* LoadTexture(std::string texturePath);
        void RenderElements(SDL_Texture* backgroundTexture);
    private:
        int width;
        int height;
        SDL_Window* gWindow;
        SDL_Surface* gScreenSurface;
        SDL_Surface* gStretched;
        Renderer* gRenderer;

        int Init();
        SDL_Surface* LoadSurface(std::string imagePath);
};