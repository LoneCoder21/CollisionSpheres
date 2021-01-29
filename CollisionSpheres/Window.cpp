#include "Window.h"

Window::Window(glm::vec2 size, std::string Title, WindowModes mode, bool db)
{
	GLFWmonitor* monitor1 = glfwGetPrimaryMonitor();
	const GLFWvidmode* vmode = glfwGetVideoMode(monitor1);

	int x1, y1, W, H;
	glfwGetMonitorWorkarea(monitor1, &x1, &y1, &W, &H);

	switch (mode)
	{
	case WindowModes::DEFAULT:
		window = glfwCreateWindow(size.x, size.y, Title.c_str(), NULL, NULL);

		glfwSetWindowPos(window, W/2 - size.x/2, H / 2 - size.y/2);

		break;
	case WindowModes::MAXIMIZED:
		window = glfwCreateWindow(size.x , size.y, Title.c_str(), NULL, NULL);

		glfwMaximizeWindow(window);
		break;
	}

	if (window == NULL)
	{
		std::cout << "Window creation failed!\n";
		glfwTerminate();
	}
	
	//hints
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
	glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);

	glfwWindowHint(GLFW_DOUBLEBUFFER, db);

	glfwSetWindowSizeCallback(window, Window::window_size_callback);

	window_size_callback(window, size.x, size.y);
}

void Window::window_size_callback(GLFWwindow* window, int width, int height)
{
	float asp = 1.0f;

	int nwidth = height * asp;
	int nheight = width * asp;

	int w1 = width < height ? width : nwidth;
	int h1 = width < height ? nheight : height;



	glViewport(std::max(0, (width - nwidth) / 2), std::max(0, (height - nheight) / 2), w1, h1);

	std::cout << "Window resized!\n";
}

Window::~Window()
{
	glfwDestroyWindow(window);
}