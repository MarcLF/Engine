#include "Modules/Includes/ModuleCamera.h"
#include "Components/ComponentCamera.h"

ModuleCamera::ModuleCamera() : Module("ModuleCamera")
{
	camera = new ComponentCamera(glm::vec3(0.0f, 0.0f, 3.0f));
}

ModuleCamera::~ModuleCamera()
{
}

bool ModuleCamera::Init()
{
	return true;
}

update_status ModuleCamera::Update(float deltaTime)
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleCamera::Delete()
{
	return true;
}

ComponentCamera* ModuleCamera::GetCamera() const
{
	return camera;
}
