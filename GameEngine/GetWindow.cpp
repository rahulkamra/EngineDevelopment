#pragma once
#include <SDL.h>
#include <Vector4.h>
SDL_Window* getWindow()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return nullptr;
	}

	math::Vector3 temp;

	SDL_Window* window = SDL_CreateWindow("Test", 100, 100, 400, 400, SDL_WINDOW_SHOWN);
	SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return window;
}


