#include "logger.h"
#include "common.h"

int main() {
  INFO("Starting Gizmo");

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(gizmoState->size.x, gizmoState->size.y, gizmoState->title.c_str(), NULL, NULL);
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

  glViewport(0, 0, gizmoState->size.x, gizmoState->size.y);
  glfwSetFramebufferSizeCallback(window, processWindowResize);

  while(!glfwWindowShouldClose(window)) {
    processInput(window);

    draw(window);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  delete gizmoState;
  return 0;
}