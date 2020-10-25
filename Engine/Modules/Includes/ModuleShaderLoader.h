#pragma once

#include "Module.h"

class ModuleShaderLoader : public Module
{
public:
	ModuleShaderLoader();
	~ModuleShaderLoader();

	bool Init() override;
	bool Delete() override;
};
