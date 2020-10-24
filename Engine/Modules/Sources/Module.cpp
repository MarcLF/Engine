#include "Modules/Includes/Module.h"

Module::Module(std::string name_) : name(name_)
{
}

Module::~Module()
{
}

bool Module::Init()
{
	return true;
}

update_status Module::PreUpdate()
{
	return update_status::UPDATE_CONTINUE;
}

update_status Module::Update()
{
	return update_status::UPDATE_CONTINUE;
}

update_status Module::PostUpdate()
{
	return update_status::UPDATE_CONTINUE;
}

bool Module::Delete()
{
	return true;
}