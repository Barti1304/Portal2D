#include "Renderer.h"

Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);

	glfwDestroyWindow(window);
}

void Renderer::initialize(int wWidth, int wHeight)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(wWidth, wHeight, "Portal2D", 0, 0);
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

	///

	this->initVAO();

	this->initShaders();

	this->initCamera();
}

void Renderer::clearScreen(glm::vec3 color)
{
	glClearColor(color.r, color.g, color.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::swapBuffers()
{
	glfwSwapBuffers(window);
}

void Renderer::renderRectangle(glm::vec2 pos)
{
	auto& shader = mapShaders["default"];
	shader.use();
	shader.setMat4("projview", camera.getProjectionViewMatrix());
	shader.setMat4("model", glm::translate(glm::mat4{ 1.0f }, glm::vec3{ pos, 1.0f }));

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

GLFWwindow* Renderer::getWindow()
{
	return window;
}

bool Renderer::isStillRunning()
{
	return !glfwWindowShouldClose(window);
}

void Renderer::debugPrintViewportRatio()
{
	int wWidth{}, wHeight{};
	glfwGetWindowSize(window, &wWidth, &wHeight);
	std::cout << "Current viewport ratio: " << (static_cast<float>(wWidth) / static_cast<float>(wHeight)) << '\n';
}

void Renderer::adjustCameraSizeToWindowSize()
{
	int wWidth{}, wHeight{};
	glfwGetWindowSize(window, &wWidth, &wHeight);

	float ratio = static_cast<float>(wWidth) / static_cast<float>(wHeight);

	int sWidth{}, sHeight{};
	if (ratio > 1)
	{
		sWidth = ratio * 16.0f;
		sHeight = 16.0f;
	}
	else
	{
		sWidth = 16.0f;
		sHeight = 16.0f / ratio;
	}

	this->camera.setSize({ sWidth, sHeight });
}

void Renderer::DynamicViewport(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Renderer::initVAO()
{
	const float vertices[]
	{
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	const unsigned int indices[]
	{
		0, 1, 2,
		1, 3, 2
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Renderer::initShaders()
{
	mapShaders.insert({ "default", std::move(Shader("shaders/default.vert", "shaders/default.frag")) });
}

void Renderer::initCamera()
{
	camera = Camera{ glm::vec2{0.0f, 0.0f}, {8.0f, 6.0f}, 1.0f };
}

