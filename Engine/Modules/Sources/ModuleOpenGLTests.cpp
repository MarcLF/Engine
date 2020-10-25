#include "Modules/Includes/ModuleOpenGLTests.h"

#include "Modules/Includes/ModuleShader.h"
#include <iostream>

ModuleOpenGLTests::ModuleOpenGLTests() : Module("ModuleOpenGLTests")
{
	VAO = NULL;
	VBO = NULL;
	EBO = NULL;
	shaderProgram = NULL;

	mainShader = new ModuleShader();
}

ModuleOpenGLTests::~ModuleOpenGLTests()
{
}

bool ModuleOpenGLTests::Init()
{
	bool ret = true;

	mainShader->LoadShader("Shaders/vertex_shader.vert", "Shaders/fragment_shader.frag");
	mainShader->CompileShader();

	CreateTriangle();

	return ret;
}

update_status ModuleOpenGLTests::Update()
{
	Draw();

	return update_status::UPDATE_CONTINUE;
}

bool ModuleOpenGLTests::Delete()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	return true;
}

void ModuleOpenGLTests::CreateTriangle()
{
	float vertices[] = {
		// positions         // colors
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,    // top left
		-0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 1.0f	 // top right
	};

	unsigned int indices[] =
	{
	0, 1, 2,
	1, 3, 2
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void ModuleOpenGLTests::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	mainShader->Use();

	// Binding VAO also binds his EBO
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
