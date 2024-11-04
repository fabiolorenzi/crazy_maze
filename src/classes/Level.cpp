#include "Level.h"

Level::Level(SDL_Surface* pScreenSurface, Renderer* pRenderer, LevelNumber levelNumber, int parentWidth, int parentHeight)
{
	parentRenderer = pRenderer;
	parentScreenSurface = pScreenSurface;
	levelNumber = levelNumber;
	width = parentWidth;
	height = parentHeight;
	currentSecond = 0.f;
	isLevelFinished = false;
	hasPlayerWon = false;
    SetBackground(levelNumber);

	if (levelNumber == LevelNumber::Menu) {
		player = nullptr;
		gameUI = nullptr;
		startTime = SDL_GetTicks();
		time = startTime;
	} else {
		maze = new Maze(levelNumber, width, height);
		player = new Player((width / 2) - 20, (height / 2) - 20, 40, 40, 0xFF, 0x00, 0x00, 0xFF, width, height);
		startTime = SDL_GetTicks();
		time = startTime;
		remainingTime = SetLevelInitialTimer(levelNumber);
		gameUI = new GameUI(1000, 20, 250, 20, player->life, remainingTime);
	}
}

Level::~Level()
{
	delete player;
	delete maze;
	delete gameUI;
	if (endGameUI) delete endGameUI;
}

void Level::RenderLevel(EndGameResult result)
{
	if (!isLevelFinished) {
		parentRenderer->Draw(maze->walls);
		parentRenderer->Draw(maze->enemies);
		parentRenderer->Draw(maze->objects);
		parentRenderer->ManageBullets(maze->enemies, *player, *gameUI);
		parentRenderer->Draw(player);
		parentRenderer->Draw(gameUI, width, height);
		if (result != EndGameResult::Waiting) {
			parentRenderer->Draw(endGameUI, width, height, result);
		}
	}
}

Player& Level::GetPlayer()
{
	return *player;
}

Maze& Level::GetMaze()
{
	return *maze;
}

GameUI& Level::GetGameUI()
{
	return *gameUI;
}

void Level::UpdateTime()
{
	time = SDL_GetTicks() - startTime;

	if ((time / 1000) >= currentSecond) {
		currentSecond += 1.f;
		remainingTime -= 1;
		gameUI->UpdateTime(remainingTime);
		maze->TriggerEnemies((int)(time / 1000));
	}
}

EndGameResult Level::CheckIfGameFinished()
{
	if (hasPlayerWon) {
		return EndGameResult::Victory;
	} else if (remainingTime < 0 && !isLevelFinished) {
		EndGame();
		std::cout << "time finished" << std::endl;
		return EndGameResult::TimeEnd;
	} else if (player->life == 0 && !isLevelFinished) {
		EndGame();
		std::cout << "death" << std::endl;
		return EndGameResult::LifeEnd;
	}

	return EndGameResult::Waiting;
}

void Level::SetBackground(LevelNumber level)
{
	switch (level) {
		case Menu:
			background = LoadBackground("assets/backgrounds/background_menu.png");
			break;
		case LevelOne:
			background = LoadBackground("assets/backgrounds/background_one.png");
			break;
		case LevelTwo:
			background = LoadBackground("assets/backgrounds/background_two.png");
			break;
		case LevelThree:
			background = LoadBackground("assets/backgrounds/background_three.png");
			break;
	}
}

SDL_Texture* Level::LoadBackground(std::string texturePath)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError());
	} else {
		texture = SDL_CreateTextureFromSurface(parentRenderer->renderer, loadedSurface);
		if (texture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return texture;
}

SDL_Surface* Level::LoadSurface(std::string imagePath)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(imagePath.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
	} else {
		optimizedSurface = SDL_ConvertSurface(loadedSurface, parentScreenSurface->format, 0);
		if (optimizedSurface == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

void Level::EndGame()
{
	isLevelFinished = true;
	player->BlockPlayer();
	gameUI->RemoveUI();
	maze->RemoveMazeArrays();
	endGameUI = new EndGameUI(0, 0, width, height);
}