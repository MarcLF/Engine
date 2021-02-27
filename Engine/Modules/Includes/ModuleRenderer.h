#pragma once

#include "Module.h"

class ModuleRenderer : public Module
{
public:
	ModuleRenderer();
	~ModuleRenderer();

	bool Init() override;
	update_status Update(float deltaTime) override;
	bool Delete() override;
};

