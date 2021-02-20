#include "Modules/Includes/ModuleImGui.h"

#include "Core/Application.h"
#include "Modules/Includes/ModuleWindow.h"

#include "ImGui/imgui.h"

ModuleImGui::ModuleImGui() : Module("ModuleImGui")
{
	io = nullptr;
}

ModuleImGui::~ModuleImGui()
{
	delete io;
}

bool ModuleImGui::Init()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO();
	(void)io;

	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(App->window->GetWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 130");

	return true;
}

update_status ModuleImGui::Update(float deltaTime)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Hello, world!");
	ImGui::Text("This is some useful text.");
	ImGui::End();

	ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}

	return update_status::UPDATE_CONTINUE;
}

bool ModuleImGui::Delete()
{
	return true;
}
