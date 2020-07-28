#pragma once

#include "Globals.h"
#include "Module.h"

#include <vector>

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
	void CreateShaders();
	void Draw();
	void CheckShadersCompilation();

private:
	const char *vertexShaderSource;
	const char *fragmentShaderSource;

	std::vector<unsigned int> shaders;

	unsigned int VAO;
	unsigned int VBO;
	unsigned int shaderProgram;
};

