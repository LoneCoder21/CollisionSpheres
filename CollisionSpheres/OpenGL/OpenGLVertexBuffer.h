#include "glad/glad.h"
#include "GLFW\glfw3.h"

#include <vector>

class OpenGLVertexBuffer
{
private:
	GLuint buffer;
	GLenum target;
	GLenum usage;
public:
	OpenGLVertexBuffer(GLenum target, GLenum usage);
	~OpenGLVertexBuffer();

	void InitBuffer(const std::vector<int>& data, int size, int start=0);
	void InitBuffer(const std::vector<float>& data, int size, int start=0);

	void FillBuffer(const std::vector<int>& data, int size, int start=0);
	void FillBuffer(const std::vector<float>& data, int size, int start=0);
};