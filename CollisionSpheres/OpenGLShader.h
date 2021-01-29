#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include <string>
#include <vector>

#pragma once

class Shader
{
private:
	GLuint vid=-1,fid=-1;
	GLuint program=-1;
public:
	Shader() : program(glCreateProgram()) {}

	void addVertexShader(const std::string& data);
	void addFragmentShader(const std::string& data);

	void compileShaders();
	std::string getCompileStatus();

	void linkShaders();
	void activateProgram();

	GLuint getProgram() { return program; }

	void setUniform1iv(const std::string& uniform, const std::vector<int>& data);
	void setUniform1fv(const std::string& uniform, const std::vector<float>& data);
	void setUniformMatrix4fv(const std::string& uniform, const float* ptr);
	void setUniform3f(const std::string& uniform, const glm::vec3& val);
	void setUniform3fv(const std::string& uniform, const std::vector<glm::vec3>& data);
	void setUniform4f(const std::string& uniform, const glm::vec4& val);
	void setUniform1i(const std::string& uniform, const int val);
	void setUniform1f(const std::string& uniform, const float val);

	~Shader();
};