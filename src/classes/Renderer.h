#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "Button.h"
#include "CatchableObject.h"
#include "EndGameUI.h"
#include "Enemy.h"
#include "GameUI.h"
#include "MenuUI.h"
#include "Player.h"
#include "Wall.h"

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
        void Draw(CatchableObject* objects[3]);
        void Draw(GameUI* gameUI, int width, int height);
        void Draw(EndGameUI* endGameUI, int width, int height);
        void Draw(MenuUI* menuUI, int width, int height);
        void Draw(Button* button, int width, int height);
        void ManageBullets(Enemy* enemies[2], Player& player, GameUI& gameUI);
        int LoadFont(TTF_Font*& font, const char* fontPath, int fontSize);
    private:
        SDL_Surface* timeTextSurface;
        SDL_Surface* endGameTextSurface;
        SDL_Surface* menuTextSurface;
        SDL_Surface* buttonTextSurface;
        SDL_Texture* timeTextTexture;
        SDL_Texture* endGameTextTexture;
        SDL_Texture* menuTextTexture;
        SDL_Texture* buttonTextTexture;
        TTF_Font* timeFont;
        TTF_Font* endGameFont;
        TTF_Font* menuFont;
        TTF_Font* buttonFont;
};