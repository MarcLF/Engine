#include "Modules/Includes/ModuleInput.h"

#include "Core/Application.h"
#include "Modules/Includes/ModuleWindow.h"

#include <Windows.h>

ModuleInput::ModuleInput() : Module("ModuleInput")
{
}

ModuleInput::~ModuleInput()
{
}

bool ModuleInput::Init()
{
	OutputDebugString(__FUNCSIG__ "\n");

	bool ret = true;
	return ret;
}

update_status ModuleInput::Update()
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleInput::Delete()
{
	OutputDebugString(__FUNCSIG__ "\n");

	return true;
}