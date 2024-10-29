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
        void Draw(UI* ui, int width, int height);
        void ManageBullets(Enemy* enemies[2], Player& player, UI& ui);
        int LoadFont(TTF_Font*& font, const char* fontPath, int fontSize);
    private:
        SDL_Surface* timeTextSurface;
        SDL_Texture* timeTextTexture;
        TTF_Font* timeFont;
};