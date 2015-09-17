#pragma once
#include<EngineTypes.h>
class SDL_Window;//forward declare whereever we can

 class DLL_EXPORT Window
{
public:
	
	explicit  Window(i32 x, i32 y , i32 width , i32 height , string title);
	~Window();

private:
	SDL_Window* nativeInstance;
};

