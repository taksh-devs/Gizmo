
#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include "utils.h"
#include "logger.h"
#include "cpu.h"
#include "memory_map/memory_map.h"

void processInput(GLFWwindow* window);
void processWindowResize(GLFWwindow* window, int width, int height);
void draw(GLFWwindow* window);
void drawUI(GLFWwindow* window);

std::string title = "Gizmo - GameBoy Emulator";
Vector2D size(800, 600);
CPU gizmoCPU;
MemoryMap gizmoMemMap;

int main() {
  INFO("Creating a simple window");

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL);
  if (window == NULL) {
    ERROR("Failed to create GLFW window");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    ERROR("Failed to initialize GLAD");
    return -1;
  }

  glViewport(0, 0, size.x, size.y);
  glfwSetFramebufferSizeCallback(window, processWindowResize);

  while(!glfwWindowShouldClose(window)) {
    processInput(window);

    draw(window);
    drawUI(window);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

void processInput(GLFWwindow* window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void processWindowResize(GLFWwindow* window, int width, int height) {
  size.x = width;
  size.y = height;
  glViewport(0, 0, width, height);
}

void draw(GLFWwindow* window) {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void drawUI(GLFWwindow* window) {
  //
}