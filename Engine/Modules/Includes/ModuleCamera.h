#pragma once

#include "Module.h"

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

#include <ThirdParty/glm/glm.hpp>
#include <ThirdParty/glm/gtc/matrix_transform.hpp>
#include <ThirdParty/glm/gtc/type_ptr.hpp>

class ComponentCamera;

class ModuleCamera : public Module
{
public:
	ModuleCamera();

	~ModuleCamera();

	bool Init() override;
	update_status Update() override;
	bool Delete() override;

	ComponentCamera* GetCamera() const;

private:
	ComponentCamera* camera;
};

