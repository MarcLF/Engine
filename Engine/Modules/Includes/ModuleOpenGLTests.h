#pragma once

#include "Globals.h"
#include "Module.h"

#include <vector>

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

class ModuleShaderLoader;

class ModuleOpenGLTests : public Module
{
public:
	ModuleOpenGLTests();
	~ModuleOpenGLTests() override;

	bool Init() override;
	update_status Update() override;
	bool Delete() override;

	void CreateTriangle();
	void Draw();

private:
	std::vector<unsigned int> shaders;

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int shaderProgram;

	ModuleShaderLoader* mainShader;
};

