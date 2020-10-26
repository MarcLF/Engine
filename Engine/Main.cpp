#include <iostream>
#include "Core/Application.h"
#include "Core/Globals.h"

Application* App = nullptr;

enum engine_states
{
	ENGINE_CREATION,
	ENGINE_START,
	ENGINE_UPDATE,
	ENGINE_FINISH,
	ENGINE_EXIT
};

int main(int argc, char** argv)
{
	int main_return = EXIT_FAILURE;
	engine_states state = ENGINE_CREATION;

	while (state != ENGINE_EXIT)
	{
		switch (state)
		{
		case ENGINE_CREATION:
		{
			App = new Application();

			state = ENGINE_START;
		}
		break;

		case ENGINE_START:
		{
			if (App->Init() == false)
			{
				state = ENGINE_FINISH;
			}
			else
			{
				state = ENGINE_UPDATE;
			}
		}
		break;

		case ENGINE_UPDATE:
		{
			update_status update_return = App->Update();

			if (update_return == update_status::UPDATE_STOP)
			{
				state = ENGINE_FINISH;
			}
		}
		break;

		case ENGINE_FINISH:
		{
			App->Delete();

			state = ENGINE_EXIT;
		}
		break;
		}
	}

	return 0;
}