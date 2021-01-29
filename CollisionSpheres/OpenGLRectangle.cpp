#include "OpenGLRectangle.h"

void OGLRectangle::update(float ts)
{
	ts = 0.02f;

	prop.pos += ts * prop.vel;

	s.activateProgram();
	vao.activateVertexObject();

	GLFWwindow* window = glfwGetCurrentContext();

	int width, height;
	glfwGetWindowSize(window, &width, &height);
	//////////////////////////////////////

	float sw = 0.0;
	prop.size = glm::vec3(width - sw * 2.0, height - sw * 2.0, 0.0);

	glm::vec3 sf = prop.size / glm::vec3(width, height, 1.0);
	glm::vec3 npos = glm::vec3(prop.pos.x*2.0,prop.pos.y*2.0,0.0) / glm::vec3(width, height, 1.0);

	glm::mat4 tm = glm::mat4(1.0f);
	tm = glm::translate(tm, npos - glm::vec3(1.0));
	tm = glm::scale(tm, glm::vec3(sf.x, sf.y, 0.0));

	s.setUniform3f("color", prop.color);
	s.setUniformMatrix4fv("trans", glm::value_ptr(tm));
}

void OGLRectangle::render()
{
	s.activateProgram();
	vao.activateVertexObject();
	glDrawArrays(GL_TRIANGLES, 0, 6);
}