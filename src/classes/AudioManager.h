#pragma once

#include <SDL_mixer.h>
#include <iostream>
#include "../enums/SoundTypes.h"

class AudioManager
{
    public:
        AudioManager();
        ~AudioManager();
        void PlayBackgroundMusic();
        void PlaySound(SoundType sound);
    private:
        Mix_Music* background_music;
        Mix_Chunk* catch_life;
        Mix_Chunk* catch_time;
        Mix_Chunk* hit;
        Mix_Chunk* lost;
        Mix_Chunk* victory;

        void LoadMusic(std::string songPath, Mix_Music*& target);
        void LoadSound(std::string soundPath, Mix_Chunk*& target);
};