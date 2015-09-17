#include <Engine.h>
#include <Window.h>
INITIALIZE_EASYLOGGINGPP

Window* Engine::init(int argc, char* argv[])
{
	START_EASYLOGGINGPP(argc, argv);
	
	mainWindow = new Window(100, 100, 1024, 768, "GameEngine");

	mainWindow->render();
	return mainWindow;
}


void Engine::onRender(int s)
{
	
}
