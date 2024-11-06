#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class Shader
{
public:
	Shader(const char* vCode, const char* fCode);
	~Shader();

	void use();

	void setInt(const char* uName, int value);
	void setFloat(const char* uName, float value);
	void setVec2(const char* uName, glm::vec2 value);
	void setVec3(const char* uName, glm::vec3 value);
	void setVec4(const char* uName, glm::vec4 value);
	void setMat4(const char* uName, glm::mat4 value);

private:
	unsigned int shaderID = 0;
};
