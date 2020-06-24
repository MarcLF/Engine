#include "ModuleInput.h"

#include "Application.h"
#include "ModuleWindow.h"

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
	return UPDATE_CONTINUE;
}

bool ModuleInput::Delete()
{
	OutputDebugString(__FUNCSIG__ "\n");

	return true;
}