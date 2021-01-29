#include "glad/glad.h"
#include "glfw/glfw3.h"

#include <vector>

#pragma once

class GLVertexArray
{
private:
	GLuint vao,vbo;

	int vbocount = 0;
public:
	GLVertexArray();

	/*
	-genvao
	-bindvao
	-specify layout
	-enable attributes



	*/

	void sendVertices(const std::vector<float>& data, int components);
	void activateVertexObject() { glBindVertexArray(vao); }

	~GLVertexArray();
};