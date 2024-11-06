#include "Renderer.h"

Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);

	glfwDestroyWindow(window);
}

void Renderer::initialize(int wWidth, int wHeight, const char* wTitle)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(wWidth, wHeight, wTitle, 0, 0);
	if (!window)
	{
		std::cerr << "[ERROR] could not open window\n";
		std::exit(1);
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "[ERROR] could not load opengl functions\n";
		std::exit(1);
	}

	glfwSwapInterval(1);
	glfwSetWindowSizeCallback(window, DynamicViewport);
}

void Renderer::swapBuffers()
{
	glfwSwapBuffers(window);
}

GLFWwindow* Renderer::getWindow()
{
	return window;
}

bool Renderer::isStillRunning()
{
	return !glfwWindowShouldClose(window);
}

void Renderer::DynamicViewport(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

