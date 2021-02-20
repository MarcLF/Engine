#pragma once

#include "Core/Globals.h"
#include "Module.h"

class ModuleInput : public Module
{
public:
	ModuleInput();
	~ModuleInput();

	bool Init() override;
	update_status Update(float deltaTime) override;
	bool Delete() override;
};

