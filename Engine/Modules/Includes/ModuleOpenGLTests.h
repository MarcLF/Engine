#pragma once

#include "Core/Globals.h"
#include "Module.h"

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

#include <ThirdParty/glm/glm.hpp>
#include <ThirdParty/glm/gtc/matrix_transform.hpp>
#include <ThirdParty/glm/gtc/type_ptr.hpp>

#include <vector>

class Shader;
class Texture;

class ModuleOpenGLTests : public Module
{
public:
	ModuleOpenGLTests();
	~ModuleOpenGLTests() override;

	bool Init() override;
	update_status Update() override;
	bool Delete() override;

	void CreateCube();
	void CreateCubes();
	void Draw();

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int shaderProgram;

	Shader* mainShader;
	Texture* containerTexture;
	Texture* awesomefaceTexture;

	glm::mat4 proj;
	glm::mat4 view;
	glm::mat4 model;

	std::vector<glm::vec3> cubePositions;
};

