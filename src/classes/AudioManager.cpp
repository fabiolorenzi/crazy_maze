#include "AudioManager.h"

AudioManager::AudioManager()
{
    LoadMusic("assets/audio/background_music.wav", background_music);
    LoadSound("assets/audio/catch_life.wav", catch_life);
    LoadSound("assets/audio/catch_time.wav", catch_time);
    LoadSound("assets/audio/hit.wav", hit);
    LoadSound("assets/audio/lost.wav", lost);
    LoadSound("assets/audio/victory.wav", victory);
}

AudioManager::~AudioManager()
{
    delete background_music;
    delete catch_life;
    delete catch_time;
    delete hit;
    delete lost;
    delete victory;
}

void AudioManager::LoadMusic(std::string songPath, SDL_Music*& target)
{
    target = Mix_LoadMUS(songPath);
    if (target == NULL) {
        printf("Failed to load the track! SDL_mixer Error: &s\n", Mix_GetError());
    }
}

void AudioManager::LoadSound(std::string soundPath, SDL_Chunk*& target)
{
    target = Mix_LoadWAV(songPath);
    if (target == NULL) {
        printf("Failed to load the track! SDL_mixer Error: &s\n", Mix_GetError());
    }
}