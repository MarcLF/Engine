#include "Modules/Includes/ModuleWindow.h"

#include "Core/Application.h"
#include "Modules/Includes/ModuleCamera.h"
#include "Components/ComponentCamera.h"

#include <Windows.h>

void mouse_callback_wrapper(GLFWwindow* window, double mouseXPos, double mouseYPos);

ModuleWindow::ModuleWindow() : Module("ModuleWindow")
{
	window = nullptr;

	screenSizeWidth = 1000;
	screenSizeHeight = 700;
}

ModuleWindow::~ModuleWindow()
{
}

bool ModuleWindow::Init()
{
	OutputDebugString(__FUNCSIG__ "\n");

	bool ret = true;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(screenSizeWidth, screenSizeHeight, "Game Engine", NULL, NULL);

	assert(window != nullptr && "Failed to create GLFW window \n");

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		OutputDebugString("Failed to initialize GLAD \n");
		ret = false;
	}

	glViewport(0, 0, screenSizeWidth, screenSizeHeight);

	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	});

	glfwSetWindowUserPointer(window, reinterpret_cast<void*>(this));
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback_wrapper);

	return ret;
}

update_status ModuleWindow::Update(float deltaTime)
{
	if (glfwWindowShouldClose(window))
	{
		OutputDebugString("Update Stop\n");

		return update_status::UPDATE_STOP;
	}

	ProcessInput(deltaTime);

	glfwSwapBuffers(window);
	glfwPollEvents();

	return update_status::UPDATE_CONTINUE;
}

bool ModuleWindow::Delete()
{
	glfwTerminate();

	return true;
}

void ModuleWindow::ProcessInput(float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		App->camera->GetCamera()->ProcessKeyboard(camera_movement::FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		App->camera->GetCamera()->ProcessKeyboard(camera_movement::BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		App->camera->GetCamera()->ProcessKeyboard(camera_movement::LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		App->camera->GetCamera()->ProcessKeyboard(camera_movement::RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		App->camera->GetCamera()->ProcessKeyboard(camera_movement::UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		App->camera->GetCamera()->ProcessKeyboard(camera_movement::DOWN, deltaTime);
}

void mouse_callback_wrapper(GLFWwindow* window, double mouseXPos, double mouseYPos)
{
	ModuleWindow* wind = reinterpret_cast<ModuleWindow*>(glfwGetWindowUserPointer(window));
	wind->MouseCallback(mouseXPos, mouseYPos);
}

void ModuleWindow::MouseCallback(double mouseXPos, double mouseYPos)
{
	App->camera->GetCamera()->ProcessMouse(mouseXPos, mouseYPos);
}

GLFWwindow* ModuleWindow::GetWindow() const
{
	OutputDebugString(__FUNCSIG__ "\n");

	return window;
}
