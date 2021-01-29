#include "GLFW\glfw3.h"
#include "glm\vec2.hpp"
#include "glm\vec3.hpp"
#include "glm\vec4.hpp"
#include "glm/gtx/string_cast.hpp"

#include <string>
#include <iostream>
#include <algorithm>

#pragma once

enum class WindowModes : int
{
	DEFAULT = 0,
	MAXIMIZED = 1,
};

class Window
{
private:
	GLFWwindow* window;
public:
	Window(glm::vec2 size, std::string Title, WindowModes mode=WindowModes::DEFAULT, bool doublebuffer=1);

	GLFWwindow* getWindowHandle() { return window; }

	//callbacks
	static void window_size_callback(GLFWwindow* window, int width, int height);


	~Window();
};