#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "OpenGLCircle.h"
#include "OpenGLRectangle.h"
#include "OpenGLShader.h"
#include "Window.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>
#include <string>

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 700,height = 800;
    Window window(glm::vec2(width, height), "BallCollider", WindowModes::DEFAULT);

    GLFWwindow* winhandle = window.getWindowHandle();
    glfwMakeContextCurrent(winhandle);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    RawFile vsShader("res\\Shaders\\CircleVertexShader.glsl");
    RawFile fsShader("res\\Shaders\\CircleFragmentShader.glsl");
    RawFile vs1Shader("res\\Shaders\\RectangleVertexShader.glsl");
    RawFile fs1Shader("res\\Shaders\\RectangleFragmentShader.glsl");

    Shader circle_shader;

    circle_shader.addVertexShader(vsShader.getContent());
    circle_shader.addFragmentShader(fsShader.getContent());

    circle_shader.compileShaders();
    circle_shader.linkShaders();

    Shader rect_shader;

    rect_shader.addVertexShader(vs1Shader.getContent());
    rect_shader.addFragmentShader(fs1Shader.getContent());

    rect_shader.compileShaders();
    rect_shader.linkShaders();

    std::cout << circle_shader.getCompileStatus() << std::endl;
    std::cout << rect_shader.getCompileStatus() << std::endl;

    GLVertexArray vao;
    vao.sendVertices({
        -1.0f, -1.0f, 0.0f, // BL
         1.0f, -1.0f, 0.0f, // BR
         1.0f,  1.0f, 0.0f,  // TR

         1.0f,  1.0f, 0.0f,  // TR
        -1.0f, 1.0f, 0.0f, // TL
        -1.0f, -1.0f, 0.0f, // BL
        }, 3);

    circle_shader.activateProgram();
    vao.activateVertexObject();
    CircleProperty prop;

    prop.color = glm::vec3(1.0, 0.0, 0.0);
    prop.pos = glm::vec3(width/2.0, height/2.0, 0.0);
    prop.vel = glm::vec3(2.0, 0.0, 0.0);
    prop.radius = 100.0f;

    OGLCircle circle(circle_shader, vao, prop);

    RectangleProperty rect_prop;

    float sidewidth = 60.0;
    sidewidth = 0.0;

    rect_prop.color = glm::vec3(1.0, 1.0, 1.0);
    rect_prop.size = glm::vec3(width - sidewidth * 2.0, height - sidewidth * 2.0, 0.0);

    rect_prop.pos = glm::vec3(width/2.0, height/2.0, 0.0);
    rect_prop.vel = glm::vec3(0.0, 0.0, 0.0);

    OGLRectangle rectangle(rect_shader, vao, rect_prop);

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double> ts;

    while (!glfwWindowShouldClose(winhandle))
    {
        start = std::chrono::high_resolution_clock::now();

        circle.update(ts.count());
        rectangle.update(ts.count());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        rectangle.render();
        circle.render();

        glfwSwapBuffers(winhandle);
        glfwPollEvents();

        end = std::chrono::high_resolution_clock::now();
        ts = end - start;
    }

    glfwTerminate();
    return 0;
}