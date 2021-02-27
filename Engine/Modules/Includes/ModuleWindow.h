#pragma once

#include "Core/Globals.h"
#include "Module.h"

#include <string>
#include <Glad/glad.h>
#include <GLFW/glfw3.h>

class ModuleWindow : public Module
{
public:
	ModuleWindow();
	~ModuleWindow() override;

	bool Init() override;
	update_status Update(float deltaTime) override;
	bool Delete() override;

	void ProcessInput(float deltaTime);

	GLFWwindow* GetWindow() const;

private:
	GLFWwindow* window;

	unsigned int screenSizeWidth;
	unsigned int screenSizeHeight;
};

