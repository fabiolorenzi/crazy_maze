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
        LoadFont(lifeFont, "assets/fonts/Jersey_10_Charted/Jersey10Charted-Regular.ttf", 28);
        if (!(IMG_Init(imgFlags) && imgFlags)) {
            printf("SDL_Image could not initialize! SDL_Error: %s\n", SDL_GetError());
        }
    }
}

Renderer::~Renderer()
{
    SDL_FreeSurface(lifeTextSurface);
    SDL_DestroyTexture(lifeTextTexture);
    SDL_DestroyRenderer(renderer);
    delete lifeFont;
    delete lifeTextTexture;
    delete lifeTextSurface;
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

void Renderer::Draw(Wall* walls[4])
{
    for (int x {}; x < 4; ++x) {
        SDL_Rect drawing = {walls[x]->x, walls[x]->y, walls[x]->width, walls[x]->height};
        SDL_SetRenderDrawColor(renderer, walls[x]->r, walls[x]->g, walls[x]->b, walls[x]->a);
        SDL_RenderFillRect(renderer, &drawing);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderDrawRect(renderer, &drawing);
    }
}

void Renderer::Draw(Enemy* enemies[2])
{
    for (int x {}; x < 2; ++x) {
        SDL_Rect drawing = {enemies[x]->x, enemies[x]->y, enemies[x]->width, enemies[x]->height};
        SDL_SetRenderDrawColor(renderer, enemies[x]->r, enemies[x]->g, enemies[x]->b, enemies[x]->a);
        SDL_RenderFillRect(renderer, &drawing);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderDrawRect(renderer, &drawing);
    }
}

void Renderer::Draw(UI* ui, int width, int height)
{
    int lifeWidth = ui-> life > 0 ? ui->width / 4 * ui->life : 0;
    SDL_Rect lifeDrawing = {ui->x, ui->y, lifeWidth, ui->height};
    SDL_Rect drawing = {ui->x, ui->y, ui->width, ui->height};
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(renderer, &drawing);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &lifeDrawing);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(renderer, &drawing);

    lifeTextSurface = TTF_RenderText_Solid(lifeFont, std::to_string(ui->life).c_str(), {255, 255, 255, 255});
    if (lifeTextSurface == NULL) {
        printf("Surface creation failed. TTF_Error: %s\n", TTF_GetError());
    }

    lifeTextTexture = SDL_CreateTextureFromSurface(renderer, lifeTextSurface);
    if (lifeTextTexture == NULL) {
        printf("Texture creation failed. SDL_Error: %s\n", SDL_GetError());
    }

    SDL_Rect lifeTextDrawing = {width - 132, 50, 100, 50};
    SDL_RenderCopy(renderer, lifeTextTexture, NULL, &lifeTextDrawing);
    SDL_FreeSurface(lifeTextSurface);
}

void Renderer::ManageBullets(Enemy* enemies[2], Player& player, UI& ui)
{
    for (int x {}; x < 2; ++x) {
        if (enemies[x]->bullet != nullptr) {
            if (enemies[x]->bullet->y >= -20 && enemies[x]->bullet->x >= -100 && (enemies[x]->bullet->hasHit || enemies[x]->bullet->x <= 1500)) {
                enemies[x]->bullet->Move();
                bool hasPlayerBeingHit = player.CheckBulletCollisions(enemies[x]->bullet);
                if (hasPlayerBeingHit) {
                    ui.UpdateLife(player.life);
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