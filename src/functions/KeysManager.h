#pragma once

#include <SDL.h>
#include "../classes/Window.h"

enum KeyCodes {
    KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT
};

void LoopEvent(bool& isRunning, Window* window);
int KeyDownManager(SDL_Event e);