#include "OpenGLVertexArray.h"

GLVertexArray::GLVertexArray()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
}

void GLVertexArray::sendVertices(const std::vector<float>& data, int components)
{
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, components, GL_FLOAT, GL_FALSE, components * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

GLVertexArray::~GLVertexArray()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}