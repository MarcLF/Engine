#pragma once

#include <glad/glad.h>
#include <string>

#include <ThirdParty/glm/glm.hpp>
#include <ThirdParty/glm/gtc/matrix_transform.hpp>
#include <ThirdParty/glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader();
	~Shader();

	void LoadShader(const char* vertexPath, const char* fragmentPath);
	void CompileShader();

	void Use();

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

	void SetMat4(const std::string& name, bool is_transpose, glm::mat4 value) const;

	unsigned int GetProgramID() const;

private:
	unsigned int programID;

	std::string vertexCode;
	std::string fragmentCode;
};
