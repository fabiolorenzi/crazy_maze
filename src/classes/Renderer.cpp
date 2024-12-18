#include "Renderer.h"

Renderer::Renderer(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_Log("Accelerated renderer could not be created! SDL_Error: %s\nSwitching to software renderer", SDL_GetError());
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    }

    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    } else {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        int imgFlags = IMG_INIT_PNG;
        int ttfFlags = TTF_Init();
        if (ttfFlags == -1) {
            printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        }
        LoadFont(timeFont, "assets/fonts/Jersey_10_Charted/Jersey10Charted-Regular.ttf", 24);
        LoadFont(endGameFont, "assets/fonts/Jersey_10_Charted/Jersey10Charted-Regular.ttf", 48);
        LoadFont(buttonFont, "assets/fonts/Jersey_10_Charted/Jersey10Charted-Regular.ttf", 32);
        LoadFont(menuFont, "assets/fonts/Jersey_10_Charted/Jersey10Charted-Regular.ttf", 48);
        if (!(IMG_Init(imgFlags) && imgFlags)) {
            printf("SDL_Image could not initialize! SDL_Error: %s\n", SDL_GetError());
        }
    }
}

Renderer::~Renderer()
{
    SDL_FreeSurface(timeTextSurface);
    SDL_DestroyTexture(timeTextTexture);
    SDL_FreeSurface(endGameTextSurface);
    SDL_DestroyTexture(endGameTextTexture);
    SDL_DestroyRenderer(renderer);
    delete timeFont;
    delete timeTextTexture;
    delete timeTextSurface;
    delete endGameFont;
    delete endGameTextTexture;
    delete endGameTextSurface;
    delete buttonFont;
    delete buttonTextTexture;
    delete buttonTextSurface;
    delete menuFont;
    delete menuTextTexture;
    delete menuTextSurface;
    IMG_Quit();
    TTF_Quit();
}

void Renderer::Reset()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void Renderer::Draw(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Rect drawing = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &drawing);
}

void Renderer::Draw(Player* player)
{
    SDL_Rect drawing = {player->x, player->y, player->width, player->height};
    SDL_SetRenderDrawColor(renderer, player->r, player->g, player->b, player->a);
    SDL_RenderFillRect(renderer, &drawing);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(renderer, &drawing);
}

void Renderer::Draw(Wall* walls[50])
{
    for (int x {}; x < 50; ++x) {
        SDL_Rect drawing = {walls[x]->x, walls[x]->y, walls[x]->width, walls[x]->height};
        SDL_SetRenderDrawColor(renderer, walls[x]->r, walls[x]->g, walls[x]->b, walls[x]->a);
        SDL_RenderFillRect(renderer, &drawing);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderDrawRect(renderer, &drawing);
    }
}

void Renderer::Draw(Enemy* enemies[10])
{
    for (int x {}; x < 10; ++x) {
        SDL_Rect drawing = {enemies[x]->x, enemies[x]->y, enemies[x]->width, enemies[x]->height};
        SDL_SetRenderDrawColor(renderer, enemies[x]->r, enemies[x]->g, enemies[x]->b, enemies[x]->a);
        SDL_RenderFillRect(renderer, &drawing);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderDrawRect(renderer, &drawing);
    }
}

void Renderer::Draw(CatchableObject* objects[5])
{
    for (int x {}; x < 5; ++x) {
        SDL_Rect drawing = {objects[x]->x, objects[x]->y, objects[x]->width, objects[x]->height};
        SDL_SetRenderDrawColor(renderer, objects[x]->r, objects[x]->g, objects[x]->b, objects[x]->a);
        SDL_RenderFillRect(renderer, &drawing);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderDrawRect(renderer, &drawing);
    }
}

void Renderer::Draw(GameUI* gameUI, int width, int height)
{
    int lifeWidth = gameUI->life > 0 ? gameUI->width / 4 * gameUI->life : 0;
    SDL_Rect lifeDrawing = {gameUI->x, gameUI->y, lifeWidth, gameUI->height};
    SDL_Rect drawing = {gameUI->x, gameUI->y, gameUI->width, gameUI->height};
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(renderer, &drawing);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &lifeDrawing);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(renderer, &drawing);

    if (gameUI->time >= 0) {
        timeTextSurface = TTF_RenderText_Blended(timeFont, std::to_string(gameUI->time).c_str(), {255, 255, 255, 255});
        if (timeTextSurface == NULL) {
            printf("timeTextSurface creation failed. TTF_Error: %s\n", TTF_GetError());
        }

        timeTextTexture = SDL_CreateTextureFromSurface(renderer, timeTextSurface);
        if (timeTextTexture == NULL) {
            printf("timeTextTexture creation failed. SDL_Error: %s\n", SDL_GetError());
        }

        int timeTextLeftMargin = gameUI->y <= 2500 ? (gameUI->time >= 10 ? 60 : 48) : 3000;
        int timeTextWidth = gameUI->time >= 10 ? 24 : 16;

        SDL_Rect timeTextDrawing = {width - timeTextLeftMargin, 50, timeTextWidth, 24};
        SDL_RenderCopy(renderer, timeTextTexture, NULL, &timeTextDrawing);
        SDL_DestroyTexture(timeTextTexture);
        SDL_FreeSurface(timeTextSurface);
    }
}

void Renderer::Draw(EndGameUI* endGameUI, int width, int height)
{
    endGameTextSurface = TTF_RenderText_Blended(endGameFont, endGameUI->message.c_str(), endGameUI->textColour);
    if (endGameTextSurface == NULL) {
        printf("endGameTextSurface creation failed. TTF_Error: %s\n", TTF_GetError());
    }

    endGameTextTexture = SDL_CreateTextureFromSurface(renderer, endGameTextSurface);
    if (endGameTextTexture == NULL) {
        printf("endGameTextTexture creation failed. SDL_Error: %s\n", SDL_GetError());
    }

    SDL_Rect endGameTextDrawing = {width / 2 - 100, height / 2 - 160, 200, 48};
    SDL_RenderCopy(renderer, endGameTextTexture, NULL, &endGameTextDrawing);
    SDL_DestroyTexture(endGameTextTexture);
    SDL_FreeSurface(endGameTextSurface);

    Draw(endGameUI->restartButton, width, height);
    Draw(endGameUI->menuButton, width, height);
}

void Renderer::Draw(MenuUI* menuUI, int width, int height)
{
    menuTextSurface = TTF_RenderText_Blended(menuFont, "Crazy Maze", {255, 0, 0, 255});
    if (menuTextSurface == NULL) {
        printf("menuTextSurface creation failed. TTF_Error: %s\n", TTF_GetError());
    }

    menuTextTexture = SDL_CreateTextureFromSurface(renderer, menuTextSurface);
    if (menuTextTexture == NULL) {
        printf("menuTextTexture creation failed. SDL_Error: %s\n", SDL_GetError());
    }

    SDL_Rect menuTextDrawing = {width / 2 - 100, height / 2 - 160, 200, 48};
    SDL_RenderCopy(renderer, menuTextTexture, NULL, &menuTextDrawing);
    SDL_DestroyTexture(menuTextTexture);
    SDL_FreeSurface(menuTextSurface);

    if (menuUI->levelNumber == LevelNumber::Menu) {
        Draw(menuUI->playButton, width, height);
        Draw(menuUI->quitButton, width, height);
    } else if (menuUI->levelNumber == LevelNumber::LevelsMenu) {
        Draw(menuUI->backButton, width, height);
        Draw(menuUI->levelOneButton, width, height);
        Draw(menuUI->levelTwoButton, width, height);
        Draw(menuUI->levelThreeButton, width, height);
    }
}

void Renderer::Draw(Button* button, int width, int height)
{
    SDL_Rect drawing = {button->x, button->y, button->width, button->height};
    SDL_SetRenderDrawColor(renderer, button->backgroundColour.r, button->backgroundColour.g, button->backgroundColour.b, button->backgroundColour.a);
    SDL_RenderFillRect(renderer, &drawing);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(renderer, &drawing);

    buttonTextSurface = TTF_RenderText_Blended(buttonFont, button->text.c_str(), button->textColour);
    if (buttonTextSurface == NULL) {
        printf("buttonTextSurface creation failed. TTF_Error: %s\n", TTF_GetError());
    }

    buttonTextTexture = SDL_CreateTextureFromSurface(renderer, buttonTextSurface);
    if (buttonTextTexture == NULL) {
        printf("buttonTextTexture creation failed. SDL_Error: %s\n", SDL_GetError());
    }

    SDL_Rect buttonTextDrawing = {button->textX, button->textY, 200, 32};
    SDL_RenderCopy(renderer, buttonTextTexture, NULL, &buttonTextDrawing);
    SDL_DestroyTexture(buttonTextTexture);
    SDL_FreeSurface(buttonTextSurface);
}

void Renderer::ManageBullets(Enemy* enemies[10], Player& player, GameUI& gameUI)
{
    for (int x {}; x < 10; ++x) {
        if (enemies[x]->bullet != nullptr) {
            if (enemies[x]->bullet->y >= -20 && enemies[x]->bullet->x >= -100 && (enemies[x]->bullet->hasHit || enemies[x]->bullet->x <= 1500)) {
                enemies[x]->bullet->Move();
                bool hasPlayerBeingHit = player.CheckBulletCollisions(enemies[x]->bullet);
                if (hasPlayerBeingHit) {
                    gameUI.UpdateLife(player.life);
                }
                SDL_Rect drawing = {enemies[x]->bullet->x, enemies[x]->bullet->y, enemies[x]->bullet->width, enemies[x]->bullet->height};
                SDL_SetRenderDrawColor(renderer, enemies[x]->bullet->r, enemies[x]->bullet->g, enemies[x]->bullet->b, enemies[x]->bullet->a);
                SDL_RenderFillRect(renderer, &drawing);
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
                SDL_RenderDrawRect(renderer, &drawing);
            } else {
                enemies[x]->DeleteBullet();
            }
        }
    }
}

int Renderer::LoadFont(TTF_Font*& font, const char* fontPath, int fontSize)
{
    font = TTF_OpenFont(fontPath, fontSize);
    if (font == NULL) {
        printf("SDL_tff could not load the font! TFF_Error: %s\n", TTF_GetError());
        return 1;
    }

    return 0;
}