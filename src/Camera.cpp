#include "Camera.h"

Camera::Camera(glm::vec2 pos, glm::vec2 sz, float zm)
{
	position = pos;
	size = sz;
	zoom = zm;
}

void Camera::operator=(Camera&& obj)
{
	if (this != &obj)
	{
		position = obj.position;
		size = obj.size;
		zoom = obj.zoom;
	}
}

glm::mat4 Camera::getProjectionViewMatrix()
{
	glm::mat4 proj = glm::ortho(-size.x / 2.0f, size.x / 2.0f, -size.y / 2.0f, size.y / 2.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4{ 1.0f }, glm::vec3{ position, 0.0f });

	return proj * view;
}
