#include "Components/Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader()
{
	programID = 0;

	vertexCode.clear();
	fragmentCode.clear();
}

Shader::~Shader()
{
	glDeleteProgram(programID);
}

void Shader::LoadShader(const char* vertexPath, const char* fragmentPath)
{
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
}

void Shader::CompileShader()
{
	const char* vShaderCode;
	const char* fShaderCode;

	vShaderCode = vertexCode.c_str();
	fShaderCode = fragmentCode.c_str();

	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	programID = glCreateProgram();
	glAttachShader(programID, vertex);
	glAttachShader(programID, fragment);
	glLinkProgram(programID);

	std::cout << programID << std::endl;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(programID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::Use()
{
	glUseProgram(programID);
}

void Shader::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}
void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}
void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

unsigned int Shader::GetProgramID() const
{
	return programID;
}
