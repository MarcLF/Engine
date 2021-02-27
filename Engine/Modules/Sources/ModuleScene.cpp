#include "Modules/Includes/ModuleScene.h"

#include "Core/Application.h"

#include <Windows.h>

ModuleScene::ModuleScene() : Module("ModuleScene")
{
}

ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init()
{
	OutputDebugString(__FUNCSIG__ "\n");

	bool ret = true;
	return ret;
}

update_status ModuleScene::Update(float deltaTime)
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::Delete()
{
	OutputDebugString(__FUNCSIG__ "\n");

	return true;
}