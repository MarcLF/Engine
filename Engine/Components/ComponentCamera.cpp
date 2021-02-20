#include "Components/ComponentCamera.h"

#include "Core/Globals.h"

ComponentCamera::ComponentCamera(glm::vec3 position_, glm::vec3 up_, float yaw_, float pitch_) :
	front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM)
{
	position = position_;
	worldUp = up_;
	yaw = yaw_;
	pitch = pitch_;
	updateCameraVectors();
}

ComponentCamera::ComponentCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw_, float pitch_) :
	front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM)
{
	position = glm::vec3(posX, posY, posZ);
	worldUp = glm::vec3(upX, upY, upZ);
	yaw = yaw;
	pitch = pitch;
	updateCameraVectors();
}

ComponentCamera::~ComponentCamera()
{
}

glm::mat4 ComponentCamera::GetViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

void ComponentCamera::ProcessKeyboard(camera_movement direction, float deltaTime)
{
	float velocity = movementSpeed * deltaTime;
	if (direction == FORWARD)
	{
		position += front * velocity;
	}
	else if (direction == BACKWARD)
	{
		position -= front * velocity;
	}
	else if (direction == LEFT)
	{
		position -= right * velocity;
	}
	else if (direction == RIGHT)
	{
		position += right * velocity;
	}
	else if (direction == UP)
	{
		position += up * velocity;
	}
	else if (direction == DOWN)
	{
		position -= up * velocity;
	}
}

// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void ComponentCamera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainpitch)
{
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainpitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	// update front, right and up Vectors using the updated Euler angles
	updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void ComponentCamera::ProcessMouseScroll(float yoffset)
{
	zoom -= (float)yoffset;
	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 45.0f)
		zoom = 45.0f;
}

void ComponentCamera::updateCameraVectors()
{
	// calculate the new front vector
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	// also re-calculate the right and up vector
	// normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}
