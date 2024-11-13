#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include "AudioManager.h"
#include "EndGameUI.h"
#include "Level.h"
#include "Maze.h"
#include "MenuUI.h"
#include "Player.h"
#include "Renderer.h"
#include "../enums/EndGameResults.h"
#include "../enums/LevelNumber.h"

class Window
{
    public:
        SDL_Surface* gScreenSurface;
        Renderer* gRenderer;
        EndGameResult gameResult;
        
        Window();
        ~Window();
        void RenderElements();
        Level& GetLevel();
        Player& GetPlayerFromLevel();
        Maze& GetMazeFromLevel();
        MenuUI& GetMenuUIFromLevel();
        EndGameUI& GetEndGameUIFromLevel();
        void SetLevel(LevelNumber newLevel);
    private:
        int width;
        int height;
        SDL_Window* gWindow;
        SDL_Surface* gStretched;
        AudioManager* audioManager;
        Level* level;

        int Init();
        void UpdateRemainingTime();
};