#include "OpenGLVertexBuffer.h"

OpenGLVertexBuffer::OpenGLVertexBuffer(GLenum target, GLenum usage) : target(target), usage(usage)
{
	glGenBuffers(1, &buffer);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	glDeleteBuffers(1, &buffer);
}

void OpenGLVertexBuffer::InitBuffer(const std::vector<int>& data, int size, int start)
{
	const int bytesize = sizeof(int);

	glBindBuffer(target, buffer);
	glBufferData(target, size * bytesize, data.data() + start, usage);
}

void OpenGLVertexBuffer::InitBuffer(const std::vector<float>& data, int size, int start)
{
	const int bytesize = sizeof(float);

	glBindBuffer(target, buffer);
	glBufferData(target, size * bytesize, data.data() + start, usage);
}

void OpenGLVertexBuffer::FillBuffer(const std::vector<int>& data, int size, int start)
{
	const int bytesize = sizeof(int);

	glBindBuffer(target, buffer);
	glBufferSubData(target, start * bytesize, size * bytesize, data.data() + start);
}

void OpenGLVertexBuffer::FillBuffer(const std::vector<float>& data, int size, int start)
{
	const int bytesize = sizeof(float);

	glBindBuffer(target, buffer);
	glBufferSubData(target, start * bytesize, size * bytesize, data.data() + start);
}