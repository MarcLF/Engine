#include "Core/Application.h"

#include "Modules/Includes/ModuleWindow.h"
#include "Modules/Includes/ModuleInput.h"
#include "Modules/Includes/ModuleCamera.h"
#include "Modules/Includes/ModuleOpenGLTests.h"
#include "Modules/Includes/ModuleImGui.h"

Application::Application()
{
	modules.push_back(window = new ModuleWindow());
	modules.push_back(input = new ModuleInput());
	modules.push_back(camera = new ModuleCamera());
	modules.push_back(openGLTests = new ModuleOpenGLTests());
	modules.push_back(imgui = new ModuleImGui());

	currentFrame = 0.0f;
	lastFrame = 0.0f;
	deltaTime = 0.0f;
}

Application::~Application()
{
}

bool Application::Init()
{
	bool ret = true;

	for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; it++)
	{
		ret = (*it)->Init();
	}

	return ret;
}

update_status Application::Update()
{
	update_status ret = update_status::UPDATE_CONTINUE;

	currentFrame = (float)glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == update_status::UPDATE_CONTINUE; it++)
	{
		ret = (*it)->Update(deltaTime);
	}

	return ret;
}

bool Application::Delete()
{
	bool ret = true;

	for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; it++)
	{
		ret = (*it)->Delete();
	}

	return ret;
}
