#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec2 pos, glm::vec2 sz);

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

private:
	glm::vec2 position;
	glm::vec2 size;
	float zoom;
};
