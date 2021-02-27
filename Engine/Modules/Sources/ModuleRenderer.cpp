#include "Modules/Includes/ModuleRenderer.h"

#include "Core/Application.h"

ModuleRenderer::ModuleRenderer() : Module("ModuleRenderer")
{
}

ModuleRenderer::~ModuleRenderer()
{
}

bool ModuleRenderer::Init()
{
	return true;
}

update_status ModuleRenderer::Update(float deltaTime)
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleRenderer::Delete()
{
	return true;
}
