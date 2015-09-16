#pragma once
#include <EngineTypes.h>
#include <SDL.h>
class DLL_EXPORT HelloEngine
{
public:
	void helloWorld();
	SDL_Window* getWindow();
};