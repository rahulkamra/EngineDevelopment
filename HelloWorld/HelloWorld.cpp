#pragma once
#include <HelloEngine.h>
#include <Window.h>
#include <SDL.h>
#include <Engine.h>
int main(int argc, char* argv[])
{
	Engine* engine = new Engine();
	Window* main =  engine->init(argc, argv);
	

	return 1;
	
}