#pragma once

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

#include <ThirdParty/glm/glm.hpp>
#include <ThirdParty/glm/gtc/matrix_transform.hpp>
#include <ThirdParty/glm/gtc/type_ptr.hpp>

enum camera_movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class ComponentCamera
{
public:
	ComponentCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
	ComponentCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

	~ComponentCamera();

	glm::mat4 GetViewMatrix();

	void ProcessKeyboard(camera_movement direction, float deltaTime);
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
	void ProcessMouseScroll(float yoffset);
	void ProcessMouse(double mouseLastXPos, double mouseLastYPos);

	void MouseRightClickReleased();

	float GetCameraFoV();

private:
	void updateCameraVectors();

private:
	// camera Attributes
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	// euler Angles
	float yaw;
	float pitch;

	// camera options
	float movementSpeed;
	float mouseSensitivity;
	float fov;

	bool isFirstClick;

	float mouseLastXPos;
	float mouseLastYPos;
};

