#pragma once

#include "Core/Globals.h"
#include "Module.h"

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init() override;
	update_status Update(float deltaTime) override;
	bool Delete() override;
};

