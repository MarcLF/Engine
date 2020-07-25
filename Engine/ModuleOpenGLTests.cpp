#include "ModuleOpenGLTests.h"

#include <iostream>

ModuleOpenGLTests::ModuleOpenGLTests() : Module("ModuleOpenGLTests")
{
	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	fragmentShaderSource = "#version 330 core"
		"out vec4 FragColor;"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
		"}\0";
}

ModuleOpenGLTests::~ModuleOpenGLTests()
{
}

bool ModuleOpenGLTests::Init()
{
	bool ret = true;

	CreateTriangle();

	return ret;
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

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	shaders.push_back(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shaders.push_back(fragmentShader);

	CheckShadersCompilation();
}

void ModuleOpenGLTests::CheckShadersCompilation()
{
	for (unsigned int i = 0; i < shaders.size(); i++)
	{
		int  success;
		char infoLog[512];
		glGetShaderiv(shaders[i], GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shaders[i], 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
}
