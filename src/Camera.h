#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera() = default;
	Camera(glm::vec2 pos, glm::vec2 sz, float zm = 1.0f);
	void operator=(Camera&& obj);

	void setPosition(glm::vec2 pos) { position = pos; };
	void setSize(glm::vec2 sz) { size = sz; };
	void setZoom(float zm) { zoom = zm; };

	glm::vec2 getPosition() { return position; };
	glm::vec2 getSize() { return size; };
	float getZoom() { return zoom; };

	glm::mat4 getProjectionViewMatrix();

private:
	glm::vec2 position;
	glm::vec2 size;
	float zoom;
};
