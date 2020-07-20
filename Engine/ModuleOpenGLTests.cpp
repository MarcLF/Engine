#include "ModuleOpenGLTests.h"


ModuleOpenGLTests::ModuleOpenGLTests() : Module("ModuleOpenGLTests")
{
}

ModuleOpenGLTests::~ModuleOpenGLTests()
{
}

bool ModuleOpenGLTests::Init()
{
	CreateTriangle();

	return true;
}

update_status ModuleOpenGLTests::Update()
{
	return UPDATE_CONTINUE;
}

bool ModuleOpenGLTests::Delete()
{
	return true;
}

void ModuleOpenGLTests::CreateTriangle()
{
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	unsigned int VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
