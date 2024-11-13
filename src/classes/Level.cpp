#include "Level.h"

Level::Level(SDL_Surface* pScreenSurface, Renderer* pRenderer, LevelNumber _levelNumber, int parentWidth, int parentHeight, AudioManager* _audioManager)
{
	parentRenderer = pRenderer;
	parentScreenSurface = pScreenSurface;
	levelNumber = _levelNumber;
	width = parentWidth;
	height = parentHeight;
	currentSecond = 0.f;
	isLevelFinished = false;
	hasPlayerWon = false;
    SetBackground(levelNumber);
	audioManager = _audioManager;

	if (levelNumber == LevelNumber::Menu || levelNumber ==  LevelNumber::LevelsMenu) {
		player = nullptr;
		gameUI = nullptr;
		maze = nullptr;
		startTime = SDL_GetTicks();
		time = startTime;
		menuUI = new MenuUI(0, 0, width, height, levelNumber);
	} else {
		maze = new Maze(levelNumber, width, height);
		player = new Player((width / 2) - 20, (height / 2) - 20, 40, 40, 0xFF, 0x00, 0x00, 0xFF, width, height, audioManager);
		startTime = SDL_GetTicks();
		time = startTime;
		remainingTime = SetLevelInitialTimer(levelNumber);
		gameUI = new GameUI(1000, 20, 250, 20, player->life, remainingTime);
	}

	audioManager->PlayBackgroundMusic();
}

Level::~Level()
{
	if (player != nullptr) delete player;
	if (maze != nullptr) delete maze;
	if (gameUI != nullptr) delete gameUI;
	delete audioManager;
	if (endGameUI != nullptr) delete endGameUI;
	if (menuUI != nullptr) delete menuUI;
}

void Level::RenderLevel(EndGameResult result)
{
	if (!isLevelFinished && levelNumber != LevelNumber::Menu && levelNumber != LevelNumber::LevelsMenu) {
		parentRenderer->Draw(maze->walls);
		parentRenderer->Draw(maze->enemies);
		parentRenderer->Draw(maze->objects);
		parentRenderer->ManageBullets(maze->enemies, *player, *gameUI);
		parentRenderer->Draw(player);
		parentRenderer->Draw(gameUI, width, height);
	} else if (levelNumber == LevelNumber::Menu || levelNumber == LevelNumber::LevelsMenu) {
		parentRenderer->Draw(menuUI, width, height);
	} else {
		parentRenderer->Draw(endGameUI, width, height);
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

MenuUI& Level::GetMenuUI()
{
	return *menuUI;
}

GameUI& Level::GetGameUI()
{
	return *gameUI;
}

EndGameUI& Level::GetEndGameUI()
{
	return *endGameUI;
}

void Level::UpdateTime()
{
	if (levelNumber != LevelNumber::Menu) {
		time = SDL_GetTicks() - startTime;

		if ((time / 1000) >= currentSecond) {
			currentSecond += 1.f;
			remainingTime -= 1;
			gameUI->UpdateTime(remainingTime);
			maze->TriggerEnemies((int)(time / 1000));
		}
	}
}

EndGameResult Level::CheckIfGameFinished(EndGameResult initial)
{
	hasPlayerWon = player->hasPlayerWon;
	if (hasPlayerWon && !isLevelFinished) {
		EndGame(EndGameResult::Victory);
		return EndGameResult::Victory;
	} else if (!isLevelFinished && remainingTime > 0 && player->life > 0) {
		return EndGameResult::Waiting;
	} else if (remainingTime < 0 && !isLevelFinished) {
		EndGame(EndGameResult::TimeEnd);
		return EndGameResult::TimeEnd;
	} else if (player->life == 0 && !isLevelFinished) {
		EndGame(EndGameResult::LifeEnd);
		return EndGameResult::LifeEnd;
	}

	return initial;
}

void Level::SetBackground(LevelNumber level)
{
	switch (level) {
		case Menu:
			background = LoadBackground("assets/backgrounds/background_menu.png");
			break;
		case LevelsMenu:
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

void Level::EndGame(EndGameResult result)
{
	isLevelFinished = true;
	player->BlockPlayer();
	endGameUI = new EndGameUI(0, 0, width, height, result);
	if (result == EndGameResult::Victory) {
		audioManager->PlaySound(SoundType::VICTORY);
	} else {
		audioManager->PlaySound(SoundType::LOST);
	}
}