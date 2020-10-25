#pragma once

#include "Module.h"

#include <glad/glad.h>

class ModuleShader : public Module
{
public:
	ModuleShader();
	~ModuleShader();

	bool Init() override;
	bool Delete() override;

	void LoadShader(const char* vertexPath, const char* fragmentPath);
	void CompileShader();

	void Use();

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

private:
	unsigned int programID;

	std::string vertexCode;
	std::string fragmentCode;
};
