#include "Utils/TraceSystem.h"

#include <iostream>

TraceSystem::TraceSystem()
{
}

TraceSystem::~TraceSystem()
{
}

void TraceSystem::Print(std::string message)
{
#if _DEBUG
	std::cout << message << std::endl;
#endif
}


