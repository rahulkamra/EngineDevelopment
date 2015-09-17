#pragma once
#include<EngineTypes.h>
#include<SDL.h>
#include<Vector2.h>
class DLL_EXPORT Window
{
public:
	
	explicit  Window(i32 x, i32 y , i32 width , i32 height , string title);
	void render();
	~Window();
	

	void setTitle(string title);
	void setPosition(math::Vector2 position);
	void setSize(math::Vector2 size);
	
	SDL_Renderer* renderer;
private:
	SDL_Window* nativeInstance;
	
	
};

