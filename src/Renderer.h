#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <unordered_map>

#include "Shader.h"

class Renderer
{
public:
	Renderer() = default;
	~Renderer();

	void initialize(int wWidth, int wHeight);

	void clearScreen(glm::vec3 color);
	void swapBuffers();


	void renderRectangle();


	GLFWwindow* getWindow();
	bool isStillRunning();

private:
	static void DynamicViewport(GLFWwindow* window, int width, int height);

	void initVAO();
	void initShaders();

	GLFWwindow* window = nullptr;
	unsigned int vao = 0, vbo = 0, ebo = 0;
	std::unordered_map<const char*, Shader> mapShaders;
};
