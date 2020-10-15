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

	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	VAO = NULL;
	VBO = NULL;
	EBO = NULL;
	shaderProgram = NULL;
}

ModuleOpenGLTests::~ModuleOpenGLTests()
{
}

bool ModuleOpenGLTests::Init()
{
	bool ret = true;

	CreateShaders();
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
	glDeleteProgram(shaderProgram);

	return true;
}

void ModuleOpenGLTests::CreateTriangle()
{
	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  
		 0.5f, -0.5f, 0.0f, 
		-0.5f, -0.5f, 0.0f,  
		-0.5f,  0.5f, 0.0f  
	};

	unsigned int indices[] = {  
	0, 1, 3,   
	1, 2, 3   
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void ModuleOpenGLTests::CreateShaders()
{
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

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
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

void ModuleOpenGLTests::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	// Binding VAO also binds his EBO
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
