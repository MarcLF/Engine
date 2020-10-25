#include "Modules\Includes\ModuleTraceSystem.h"

#include <iostream>

ModuleTraceSystem::ModuleTraceSystem() : Module("ModuleTraceSystem")
{
}

ModuleTraceSystem::~ModuleTraceSystem()
{
}

void ModuleTraceSystem::Print(std::string message)
{
#if _DEBUG
	std::cout << message << std::endl;
#endif
}


