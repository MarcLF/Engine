#include "Application.h"

#include "ModuleWindow.h"
#include "ModuleInput.h"

Application::Application()
{
	modules.push_back(window = new ModuleWindow());
	modules.push_back(input = new ModuleInput());
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
	update_status ret = UPDATE_CONTINUE;

	for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; it++)
	{
		ret = (*it)->Update();
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
