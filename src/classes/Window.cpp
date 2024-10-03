#include "Window.h"

Window::Window()
{
    width = 1280;
    height = 720;

    Init();
}

Window::~Window()
{
	delete level;
	delete gRenderer;
    SDL_FreeSurface(gStretched);
	gStretched = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

int Window::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	else
	{
		gWindow = SDL_CreateWindow(
            "CrazyMaze",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN
        );

		if (gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return -1;
		} else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = new Renderer(gWindow);
			level = new Level(gScreenSurface, gRenderer, LevelNumber::LevelOne, width, height);
		}
	}
	return 0;
}

void Window::RenderElements()
{
	gRenderer->Reset();

	SDL_RenderCopy(gRenderer->renderer, level->background, NULL, NULL);
	level->RenderLevel();
	level->UpdateTime();

	SDL_RenderPresent(gRenderer->renderer);
}

Player& Window::GetPlayerFromLevel()
{
	return level->GetPlayer();
}

Maze& Window::GetMazeFromLevel()
{
	return level->GetMaze();
}