#include "OpenGLShader.h"
#include <iostream>

void Shader::addVertexShader(const std::string& data)
{
	vid = glCreateShader(GL_VERTEX_SHADER);
	const char* str = data.c_str();

	glShaderSource(vid, 1, &str, NULL);
}

void Shader::addFragmentShader(const std::string& data)
{
	fid = glCreateShader(GL_FRAGMENT_SHADER);
	const char* str = data.c_str();

	glShaderSource(fid, 1, &str, NULL);
}

void Shader::compileShaders()
{
	glCompileShader(vid);
	glCompileShader(fid);
}

std::string Shader::getCompileStatus()
{
	GLchar VS_SHADER_LOG[500], FS_SHADER_LOG[500];

	int VL, FL;

	glGetShaderInfoLog(vid, 500, &VL, VS_SHADER_LOG);
	glGetShaderInfoLog(fid, 500, &FL, FS_SHADER_LOG);

	std::string log;

	for (int i = 0; i < VL; ++i)
		log.push_back(VS_SHADER_LOG[i]);

	for (int i = 0; i < FL; ++i)
		log.push_back(FS_SHADER_LOG[i]);

	return log;
}

void Shader::linkShaders()
{
	glAttachShader(program, vid);
	glAttachShader(program, fid);

	glLinkProgram(program);
}

void Shader::activateProgram()
{
	glUseProgram(program);
}

void Shader::setUniform1iv(const std::string& uniform, const std::vector<int>& data)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniform1iv(loc, data.size(), data.data());
}

void Shader::setUniform1fv(const std::string& uniform, const std::vector<float>& data)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniform1fv(loc, data.size(), data.data());
}

void Shader::setUniformMatrix4fv(const std::string& uniform, const float* ptr)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniformMatrix4fv(loc, 1, GL_FALSE, ptr);
}

void Shader::setUniform3f(const std::string& uniform, const glm::vec3& val)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniform3f(loc, val.x, val.y, val.z);
}

void Shader::setUniform3fv(const std::string& uniform, const std::vector<glm::vec3>& data)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniform3fv(loc, data.size(), reinterpret_cast<const float*>(data.data()));
}

void Shader::setUniform4f(const std::string& uniform, const glm::vec4& val)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniform4f(loc, val.x, val.y, val.z, val.w);
}

void Shader::setUniform1i(const std::string& uniform, const int val)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniform1i(loc, val);
}

void Shader::setUniform1f(const std::string& uniform, const float val)
{
	GLuint loc = glGetUniformLocation(program, uniform.c_str());
	glUniform1f(loc, val);
}

Shader::~Shader() {
	glDeleteShader(vid);
	glDeleteShader(fid);
	glDeleteProgram(program);
}