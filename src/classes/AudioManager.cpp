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
    Mix_FreeChunk(catch_life);
    Mix_FreeChunk(catch_time);
    Mix_FreeChunk(hit);
    Mix_FreeChunk(lost);
    Mix_FreeChunk(victory);
    Mix_FreeMusic(background_music);
}

void AudioManager::LoadMusic(std::string songPath, Mix_Music*& target)
{
    target = Mix_LoadMUS(songPath.c_str());
    if (target == NULL) {
        printf("Failed to load the track! SDL_mixer Error: &s\n", Mix_GetError());
    }
}

void AudioManager::LoadSound(std::string soundPath, Mix_Chunk*& target)
{
    target = Mix_LoadWAV(soundPath.c_str());
    if (target == NULL) {
        printf("Failed to load the track! SDL_mixer Error: &s\n", Mix_GetError());
    }
}

void AudioManager::PlayBackgroundMusic()
{
    Mix_PlayMusic(background_music, -1);
}

void AudioManager::PlaySound(SoundType sound)
{
    switch (sound) {
        case SoundType::CATCH_LIFE:
            Mix_PlayChannel(-1, catch_life, 0);
            break;
        case SoundType::CATCH_TIME:
            Mix_PlayChannel(-1, catch_time, 0);
            break;
        case SoundType::HIT:
            Mix_PlayChannel(-1, hit, 0);
            break;
        case SoundType::LOST:
            Mix_PlayChannel(-1, lost, 0);
            break;
        case SoundType::VICTORY:
            Mix_PlayChannel(-1, victory, 0);
            break;
    }
}