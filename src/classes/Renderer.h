#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Player.h"
#include "Wall.h"
#include "UI.h"

class Renderer
{
    public:
        SDL_Renderer* renderer;
        Renderer(SDL_Window* window);
        ~Renderer();
        void Reset();
        void Draw(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void Draw(Player* player);
        void Draw(Wall* walls[4]);
        void Draw(Enemy* enemies[2]);
        void Draw(UI* ui);
        void ManageBullets(Enemy* enemies[2], Player& player, UI& ui);
        int LoadFont(TTF_Font* font, const char* fontPath, int fontSize, SDL_Color* fontColour, SDL_Color colour);
    private:
        SDL_Surface* lifeTextSurface;
        SDL_Texture* lifeTextTexture;
        TTF_Font* lifeFont;
        SDL_Color* lifeFontColour;
};