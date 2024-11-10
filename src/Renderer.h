#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <unordered_map>

#include "Shader.h"
#include "Camera.h"

class Renderer
{
public:
	Renderer() = default;
	~Renderer();

	void initialize(int wWidth, int wHeight);

	void clearScreen(glm::vec3 color);
	void swapBuffers();


	void renderRectangle(glm::vec3 color, glm::vec2 pos, glm::vec2 size, float rotation);


	GLFWwindow* getWindow();
	bool isStillRunning();

	Camera& getCamera() { return camera; };

	void adjustCameraSizeToWindowSize(bool debugOutput = false);

private:
	static void DynamicViewport(GLFWwindow* window, int width, int height);

	void initVAO();
	void initShaders();
	void initCamera();

	Camera camera;
	GLFWwindow* window = nullptr;
	unsigned int vao = 0, vbo = 0, ebo = 0;
	std::unordered_map<const char*, Shader> mapShaders;
};
