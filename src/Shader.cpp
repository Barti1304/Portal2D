#include "Shader.h"

Shader::Shader(const char* vCode, const char* fCode)
{
	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vCode, 0);
	glCompileShader(vShader);

	{
		int success{};
		char log[512]{};
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vShader, 512, 0, log);
			std::cerr << "[ERROR] vertex shader:\n" << log << '\n';
		}
	}

	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fCode, 0);
	glCompileShader(fShader);

	{
		int success{};
		char log[512]{};
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fShader, 512, 0, log);
			std::cerr << "[ERROR] fragment shader:\n" << log << '\n';
		}
	}

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vShader);
	glAttachShader(shaderID, fShader);
	glLinkProgram(shaderID);

	{
		int success{};
		char log[512]{};
		glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderID, 512, 0, log);
			std::cerr << "[ERROR] shader program:\n" << log << '\n';
		}
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

Shader::~Shader()
{
	glDeleteProgram(shaderID);
}

void Shader::use()
{
	glUseProgram(shaderID);
}

void Shader::setInt(const char* uName, int value)
{
	glUniform1i(glGetUniformLocation(shaderID, uName), value);
}

void Shader::setFloat(const char* uName, float value)
{
	glUniform1f(glGetUniformLocation(shaderID, uName), value);
}

void Shader::setVec2(const char* uName, glm::vec2 value)
{
	glUniform2f(glGetUniformLocation(shaderID, uName), value.x, value.y);
}

void Shader::setVec3(const char* uName, glm::vec3 value)
{
	glUniform3f(glGetUniformLocation(shaderID, uName), value.x, value.y, value.z);
}

void Shader::setVec4(const char* uName, glm::vec4 value)
{
	glUniform4f(glGetUniformLocation(shaderID, uName), value.x, value.y, value.z, value.w);
}

void Shader::setMat4(const char* uName, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderID, uName), 1, GL_FALSE, glm::value_ptr(value));
}
