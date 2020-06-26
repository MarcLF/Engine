#pragma once

#include "Module.h"

class ModuleImGui : public Module
{
public:
	ModuleImGui();
	~ModuleImGui();

	bool Init() override;
	update_status Update() override;
	bool Delete() override;
};

