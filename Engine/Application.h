#pragma once

#include <list>
#include "Module.h"

class ModuleWindow;
class ModuleInput;
class ModuleOpenGLTests;

class Application
{
public:
	Application();
	virtual ~Application();

	virtual bool Init();

	virtual update_status Update();

	virtual bool Delete();

private:
	std::list<Module*> modules;

public:
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleOpenGLTests* openGLTests = nullptr;
};

extern Application* App;