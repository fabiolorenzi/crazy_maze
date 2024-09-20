#include "Level.h"

Level::Level(SDL_Surface* pScreenSurface, Renderer* pRenderer, LevelNumber levelNumber, int parentWidth, int parentHeight)
{
	parentRenderer = pRenderer;
	parentScreenSurface = pScreenSurface;
	levelNumber = levelNumber;
	width = parentWidth;
	height = parentHeight;
    SetBackground(levelNumber);

	if (levelNumber == LevelNumber::Menu) {
		player = nullptr;
	} else {
		maze = new Maze(levelNumber, width, height);
		player = new Player((width / 2) - 20, (height / 2) - 20, 40, 40, 0xFF, 0x00, 0x00, 0xFF);
	}
}

Level::~Level()
{
	delete player;
	delete maze;
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

void Level::RenderLevel()
{
	parentRenderer->Draw(maze->walls);
	parentRenderer->Draw(player);
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