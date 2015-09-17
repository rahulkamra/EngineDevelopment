#include<Window.h>
#include<SDL.h>
#include<Engine.h>

Window::Window(i32 x, i32 y, i32 width, i32 height,string title)
{
	this->nativeInstance = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);
	if (this->nativeInstance == nullptr)
	{
		LOG(ERROR) << "Could not create window:" << SDL_GetError();
		return;
	}
}

Window::~Window()
{
	SDL_DestroyWindow(nativeInstance);
	delete nativeInstance;
}
