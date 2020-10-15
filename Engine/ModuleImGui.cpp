#include "ModuleImGui.h"

#include "Application.h"
#include "ModuleWindow.h"

#include "ImGui/imgui.h"

ModuleImGui::ModuleImGui() : Module("ModuleImGui")
{
}

ModuleImGui::~ModuleImGui()
{
}

bool ModuleImGui::Init()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(App->window->GetWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 130");

	return true;
}

update_status ModuleImGui::Update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Hello, world!");
    ImGui::Text("This is some useful text.");
    ImGui::End();

	ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	return update_status::UPDATE_CONTINUE;
}

bool ModuleImGui::Delete()
{
	return true;
}
