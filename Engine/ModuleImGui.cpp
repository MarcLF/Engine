#include "ModuleImGui.h"



ModuleImGui::ModuleImGui() : Module("ModuleImGui")
{
}


ModuleImGui::~ModuleImGui()
{
}

bool ModuleImGui::Init()
{
	return true;
}

update_status ModuleImGui::Update()
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleImGui::Delete()
{
	return true;
}
