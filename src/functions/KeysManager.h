#pragma once

#include <SDL.h>
#include "../classes/Window.h"
#include "../enums/EndGameResults.h"
#include "../enums/LevelNumber.h"

enum KeyCodes {
    KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT
};

void LoopEvent(bool& isRunning, Window*& window, EndGameResult result);
int KeyDownManager(SDL_Event e);