#pragma once

#include "Globals.h"
#include "Module.h"

class ModuleInput : public Module
{
public:
	ModuleInput();
	~ModuleInput();

	bool Init() override;

	update_status Update() override;

	bool Delete() override;
};

