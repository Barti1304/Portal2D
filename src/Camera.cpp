#include "Camera.h"

Camera::Camera(glm::vec2 pos, glm::vec2 sz, float zm)
{
	position = pos;
	size = sz;
	zoom = zm;
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 view = glm::translate(glm::mat4{ 1.0f }, glm::vec3{ position, 1.0f });
	return view;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return glm::ortho(-size.x / 2.0f, size.x / 2.0f, -size.y / 2.0f, size.y / 2.0f, -1.0f, 1.0f);
}
