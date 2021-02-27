#include "Modules/Includes/ModuleWindow.h"

#include "Core/Application.h"
#include "Modules/Includes/ModuleCamera.h"
#include "Components/ComponentCamera.h"

#include <Windows.h>

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void mouse_callback(GLFWwindow* window, double mouseXPos, double mouseYPos);
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

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

	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);

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

GLFWwindow* ModuleWindow::GetWindow() const
{
	OutputDebugString(__FUNCSIG__ "\n");

	return window;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		glfwSetCursorPosCallback(window, NULL);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		App->camera->GetCamera()->MouseRightClickReleased();
	}
}

void mouse_callback(GLFWwindow* window, double mouseXPos, double mouseYPos)
{
	App->camera->GetCamera()->ProcessMouse(mouseXPos, mouseYPos);
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{
	App->camera->GetCamera()->ProcessMouseScroll(yOffset);
}
