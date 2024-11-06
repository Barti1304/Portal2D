#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Renderer
{
public:
	Renderer() = default;
	~Renderer();

	void initialize(int wWidth, int wHeight, const char* wTitle);

private:
	GLFWwindow* gameWindow = nullptr;
	unsigned int vao = 0, vbo = 0, ebo = 0;
};
