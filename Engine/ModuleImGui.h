#pragma once

#include "Module.h"

class ImGuiIO;

class ModuleImGui : public Module
{
public:
	ModuleImGui();
	~ModuleImGui();

	bool Init() override;
	update_status Update() override;
	bool Delete() override;

private:
	ImGuiIO *io;
};

