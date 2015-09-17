#include<Window.h>
#include<Engine.h>

Window::Window(i32 x, i32 y, i32 width, i32 height,string title)
{
	this->nativeInstance = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);
	if (this->nativeInstance == nullptr)
	{
		LOG(ERROR) << "Could not create window:" << SDL_GetError();
		return;
	}
	renderer = SDL_CreateRenderer(this->nativeInstance, -1, SDL_RENDERER_ACCELERATED);
}
void Window::render()
{
	if (this->nativeInstance == nullptr)
		return;

	SDL_Event* event = new SDL_Event();
	while (event->type != SDL_QUIT)
	{
		SDL_PollEvent(event);
		
	//	SDL_RenderClear(renderer);
		//SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->nativeInstance);

	
	//why we cannot delete this->nativeInstance , dont know
	delete event;
}

Window::~Window()
{
	
}

void Window::setTitle(string title)
{
	SDL_SetWindowTitle(this->nativeInstance, title.c_str());
}

void Window::setPosition(math::Vector2 position)
{
	SDL_SetWindowPosition(this->nativeInstance, position.x, position.y);
}

void Window::setSize(math::Vector2 size)
{
	SDL_SetWindowSize(this->nativeInstance, size.x, size.y);
}