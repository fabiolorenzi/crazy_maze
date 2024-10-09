#pragma once

#include <SDL.h>
#include <iostream>
#include "Maze.h"
#include "Player.h"
#include "Renderer.h"
#include "UI.h"
#include "../enums/LevelNumber.h"
#include "../functions/LevelElementsManager.h"

class Level
{
    public:
        LevelNumber levelNumber;
        SDL_Texture* background;

        Level(SDL_Surface* pScreenSurface, Renderer* pRenderer, LevelNumber levelNumber, int parentWidth, int parentHeight);
        ~Level();
        void RenderLevel();
        Player& GetPlayer();
        Maze& GetMaze();
        void UpdateTime();
    private:
        int width, height;
        Uint32 startTime, time;
        float currentSecond;
        int remainingTime;
        Maze* maze;
        Player* player;
        UI* ui;
        SDL_Surface* parentScreenSurface;
        Renderer* parentRenderer;

        void SetBackground(LevelNumber level);
        SDL_Texture* LoadBackground(std::string texturePath);
        SDL_Surface* LoadSurface(std::string imagePath);
};