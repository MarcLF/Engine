#pragma once

#include <string>
#include "Core/Globals.h"

class Module
{
public:
	Module(std::string name);
	virtual ~Module();

	virtual bool Init();

	virtual update_status PreUpdate();
	virtual update_status Update();
	virtual update_status PostUpdate();

	virtual bool Delete();

private:
	std::string name;
};

