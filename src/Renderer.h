#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Renderer
{
public:
	Renderer() = default;
	~Renderer();

	void initialize(int wWidth, int wHeight, const char* wTitle);

	void swapBuffers();

	GLFWwindow* getWindow();
	bool isStillRunning();

private:
	static void DynamicViewport(GLFWwindow* window, int width, int height);

	GLFWwindow* window = nullptr;
	unsigned int vao = 0, vbo = 0, ebo = 0;
};
