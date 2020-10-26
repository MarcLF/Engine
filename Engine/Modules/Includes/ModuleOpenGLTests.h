#pragma once

#include "Core/Globals.h"
#include "Module.h"

#include <vector>

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

class Shader;

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
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int shaderProgram;

	Shader* mainShader;
};

