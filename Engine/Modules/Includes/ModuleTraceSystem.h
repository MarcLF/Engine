#pragma once

#include "Module.h"

#include <string>

class ModuleTraceSystem : public Module
{
public:
	ModuleTraceSystem();
	~ModuleTraceSystem();

	void Print(std::string message);
};

