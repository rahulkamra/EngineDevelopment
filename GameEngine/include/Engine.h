#pragma once
#include <easylogging++.h>
#include <EngineTypes.h>

class Window;
class DLL_EXPORT Engine
{
public:
	Window* init(int argc, char* argv[]);


private:
	Window* mainWindow;
	void onRender(int x);
};

