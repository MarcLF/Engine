#pragma once

#include "Module.h"

struct ImGuiIO;

class ModuleImGui : public Module
{
public:
	ModuleImGui();
	~ModuleImGui();

	bool Init() override;
	update_status Update(float deltaTime) override;
	bool Delete() override;

private:
	ImGuiIO* io;
};

