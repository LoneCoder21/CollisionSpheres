#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "RawFileLoader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLShader.h"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma once

struct RectangleProperty
{
	glm::vec3 pos = glm::vec3(0.0f);
	glm::vec3 size = glm::vec3(10.0f);
	glm::vec3 vel = glm::vec3(0.0f);
	glm::vec3 color = glm::vec3(1.0f);
};

class OGLRectangle
{
private:
	Shader& s;
	GLVertexArray& vao;

	RectangleProperty prop;
public:
	OGLRectangle(Shader& s, GLVertexArray& vao, const RectangleProperty& prop) : s(s), vao(vao), prop(prop) {}

	void update(float ts);
	void render();
};