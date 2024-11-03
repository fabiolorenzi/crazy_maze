#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Level.h"
#include "Maze.h"
#include "Player.h"
#include "Renderer.h"
#include "../enums/EndGameResults.h"
#include "../enums/LevelNumber.h"

class Window
{
    public:
        SDL_Surface* gScreenSurface;
        Renderer* gRenderer;
        
        Window();
        ~Window();
        void RenderElements();
        Player& GetPlayerFromLevel();
        Maze& GetMazeFromLevel();
    private:
        int width;
        int height;
        EndGameResult gameResult;
        SDL_Window* gWindow;
        SDL_Surface* gStretched;
        Level* level;

        int Init();
        void UpdateRemainingTime();
};