#pragma once

#include <list>
#include "Module.h"

class ModuleWindow;
class ModuleInput;

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
};

extern Application* App;