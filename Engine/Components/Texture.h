#pragma once

#include <glad/glad.h>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	void LoadTexture(std::string texturePath, bool hasAlpha);

	unsigned int GetTexture() const;

private:
	int width;
	int	height;
	int nrChannels;

	unsigned int texture;
};
