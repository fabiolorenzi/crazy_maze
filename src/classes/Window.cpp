#include "Window.h"

Window::Window()
{
    width = 1280;
    height = 720;
	gameResult = EndGameResult::Waiting;

    Init();
}

Window::~Window()
{
    SDL_FreeSurface(gStretched);
	gStretched = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	delete level;
	delete gRenderer;
	delete audioManager;
	Mix_Quit();
	SDL_Quit();
}

void Window::RenderElements()
{
	UpdateRemainingTime();
	gameResult = level->CheckIfGameFinished(gameResult);
	level->GetGameUI().UpdateLife(level->GetPlayer().life);

	gRenderer->Reset();

	SDL_RenderCopy(gRenderer->renderer, level->background, NULL, NULL);
	level->RenderLevel(gameResult);
	level->UpdateTime();

	SDL_RenderPresent(gRenderer->renderer);
}

Level& Window::GetLevel()
{
	return *level;
}

Player& Window::GetPlayerFromLevel()
{
	return level->GetPlayer();
}

Maze& Window::GetMazeFromLevel()
{
	return level->GetMaze();
}

EndGameUI& Window::GetEndGameUIFromLevel()
{
	return level->GetEndGameUI();
}

void Window::SetLevel(LevelNumber newLevel)
{
	level = new Level(gScreenSurface, gRenderer, newLevel, width, height);
}

int Window::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	} else {
		gWindow = SDL_CreateWindow(
            "CrazyMaze",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN
        );

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			printf("SDL_Mixer could not initialize! SDL_mixer Error: $s\n", Mix_GetError());
			return -1;
		} else {
			audioManager = new AudioManager();
		}

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

void Window::UpdateRemainingTime()
{
	if (level->GetPlayer().hasToAddTime) {
		level->remainingTime += 30;
		level->GetPlayer().hasToAddTime = false;
	}
}