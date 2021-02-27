#pragma once

#include <list>
#include "Modules/Includes/Module.h"

class ModuleWindow;
class ModuleScene;
class ModuleCamera;
class ModuleRenderer;
class ModuleOpenGLTests;
class ModuleImGui;

class Application
{
public:
	Application();
	virtual ~Application();

	virtual bool Init();

	virtual update_status Update();

	virtual bool Delete();

public:
	ModuleWindow* window = nullptr;
	ModuleScene* input = nullptr;
	ModuleCamera* camera = nullptr;
	ModuleRenderer* renderer = nullptr;
	ModuleOpenGLTests* openGLTests = nullptr;
	ModuleImGui* imgui = nullptr;

private:
	std::list<Module*> modules;

	float currentFrame;
	float lastFrame;
	float deltaTime;
};

extern Application* App;