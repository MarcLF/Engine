#include "Modules\Includes\ModuleCamera.h"

ModuleCamera::ModuleCamera() : Module("ModuleCamera")
{
}

ModuleCamera::~ModuleCamera()
{
}

bool ModuleCamera::Init()
{
	return true;
}

update_status ModuleCamera::Update()
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleCamera::Delete()
{
	return true;
}
