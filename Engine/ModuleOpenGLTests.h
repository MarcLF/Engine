#pragma once

#include "Globals.h"
#include "Module.h"

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

class ModuleOpenGLTests : public Module
{
public:
	ModuleOpenGLTests();
	~ModuleOpenGLTests() override;

	bool Init() override;
	update_status Update() override;
	bool Delete() override;

	void CreateTriangle();
};

