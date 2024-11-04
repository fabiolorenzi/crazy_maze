#pragma once

#include <SDL.h>
#include <iostream>
#include "EndGameUI.h"
#include "Maze.h"
#include "Player.h"
#include "Renderer.h"
#include "GameUI.h"
#include "../enums/LevelNumber.h"
#include "../enums/EndGameResults.h"
#include "../functions/LevelElementsManager.h"

class Level
{
    public:
        LevelNumber levelNumber;
        SDL_Texture* background;
        Uint32 time;
        int remainingTime;
        bool hasPlayerWon;

        Level(SDL_Surface* pScreenSurface, Renderer* pRenderer, LevelNumber levelNumber, int parentWidth, int parentHeight);
        ~Level();
        void RenderLevel(EndGameResult result);
        Player& GetPlayer();
        Maze& GetMaze();
        GameUI& GetGameUI();
        void UpdateTime();
        EndGameResult CheckIfGameFinished();
    private:
        int width, height;
        Uint32 startTime;
        float currentSecond;
        bool isLevelFinished;
        EndGameResult result;
        Maze* maze;
        Player* player;
        GameUI* gameUI;
        EndGameUI* endGameUI;
        SDL_Surface* parentScreenSurface;
        Renderer* parentRenderer;

        void SetBackground(LevelNumber level);
        SDL_Texture* LoadBackground(std::string texturePath);
        SDL_Surface* LoadSurface(std::string imagePath);
        void EndGame();
};