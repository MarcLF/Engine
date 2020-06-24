#include "Module.h"


Module::Module(std::string name_) : name(name_)
{}

Module::~Module()
{}

bool Module::Init() 
{
	return true;
}

update_status Module::PreUpdate() 
{
	return UPDATE_CONTINUE;
}

update_status Module::Update()
{
	return UPDATE_CONTINUE;
}

update_status Module::PostUpdate()
{
	return UPDATE_CONTINUE;
}

bool Module::Delete()
{
	return true;
}