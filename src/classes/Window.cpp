#include "Window.h"

Window::Window()
{
    width = 1280;
    height = 720;
	gameResult = EndGameResult::Waiting;
	quit = false;

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
	if (level->levelNumber != LevelNumber::Menu && level->levelNumber != LevelNumber::LevelsMenu) {
		UpdateRemainingTime();
		gameResult = level->CheckIfGameFinished(gameResult);
		level->GetGameUI().UpdateLife(level->GetPlayer().life);
	} else {
		gameResult = EndGameResult::Waiting;
	}

	gRenderer->Reset();

	SDL_RenderCopy(gRenderer->renderer, level->background, NULL, NULL);
	level->RenderLevel(gameResult);

	if (level->levelNumber != LevelNumber::Menu && level->levelNumber != LevelNumber::LevelsMenu) {
		level->UpdateTime();
	}

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

MenuUI& Window::GetMenuUIFromLevel()
{
	return level->GetMenuUI();
}

EndGameUI& Window::GetEndGameUIFromLevel()
{
	return level->GetEndGameUI();
}

void Window::SetLevel(LevelNumber newLevel)
{
	level = new Level(gScreenSurface, gRenderer, newLevel, width, height, audioManager);
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
			level = new Level(gScreenSurface, gRenderer, LevelNumber::Menu, width, height, audioManager);
		}
	}
	return 0;
}

void Window::UpdateRemainingTime()
{
	if (level->GetPlayer().hasToAddTime) {
		level->remainingTime += 60;
		level->GetPlayer().hasToAddTime = false;
	}
}